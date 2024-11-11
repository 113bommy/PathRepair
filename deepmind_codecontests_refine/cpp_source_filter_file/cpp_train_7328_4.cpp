#include <bits/stdc++.h>
using namespace std;
int cases;
long long n;
map<pair<long long, long long>, pair<long long, long long> > m;
pair<long long, long long> go(long long num, long long mayor) {
  pair<long long, long long> res = make_pair(0, 0);
  if (num == 0) return res;
  if (num < 10) {
    if (num < mayor) {
      res.second = mayor - num;
    }
    res.first = 1;
    return res;
  }
  pair<long long, long long> current = make_pair(num, mayor);
  if (m.find(current) != m.end()) return m[current];
  long long pot = 1;
  for (int i = 0; i < 19; i++) {
    if (pot > num / 10) break;
    pot *= 10;
  }
  while (true) {
    long long dig = num / pot;
    long long mx = max(mayor, dig);
    pair<long long, long long> answer = go(num % pot, max(dig, mx));
    res.first += answer.first;
    num -= num % pot;
    if (answer.second == 0 && mx > 0) {
      res.first++;
      num -= mx;
    } else
      num -= answer.second;
    if (dig == 0) break;
  }
  res.second = num;
  return m[current] = res;
}
int main() {
  cin >> n;
  cout << go(n, 0).first << endl;
  return 0;
}
