#include <bits/stdc++.h>
using namespace std;
long long n;
string s = "";
queue<long long> good, bad;
int main() {
  scanf("%lld", &n);
  cin >> s;
  for (long long i = 0; i < s.length(); i++) {
    if (s[i] == 'D')
      good.push(i);
    else
      bad.push(i);
  }
  long long pos = 0;
  while (good.size() != 0 && bad.size() != 0) {
    long long p1 = good.front();
    long long p2 = bad.front();
    if ((p1 > pos && p2 > pos) || (p1 < pos && p2 < pos))
      pos = min(p1, p2);
    else if (pos > p1 && pos < p2)
      pos = p2;
    else if (pos < p1 && pos > p2)
      pos = p1;
    if (pos == p1) {
      bad.pop();
      good.push(p1);
      good.pop();
    } else {
      good.pop();
      bad.push(p2);
      bad.pop();
    }
    pos++;
  }
  if (bad.size() == 0)
    puts("D");
  else
    puts("R");
  return 0;
}
