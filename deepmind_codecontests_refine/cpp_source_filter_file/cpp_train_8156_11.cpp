#include <bits/stdc++.h>
using namespace std;
bool arr[1000];
string convert_int(long long int n) {
  stringstream ss;
  ss << n;
  return ss.str();
}
int convert_str(string s) {
  stringstream ss(s);
  long long int result;
  return (ss >> result ? result : 0);
}
void sieve(int bound) {
  int s = bound + 1;
  arr[0] = 0;
  arr[1] = 1;
  for (int i = 2; i < s; i++) {
    if (arr[i]) {
      for (int j = i * i; j < s; j++) {
        arr[j] = 0;
      }
    }
  }
}
bool isprime(int idx) { return arr[idx]; }
int divisors(int n, int b) { return (n / b); }
long long int gcd(long long int a, long long b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
long long int lcm(long long int a, long long int b) {
  return (a * b) / gcd(a, b);
}
int main() {
  set<pair<int, int> > s;
  int x, y, a, b;
  cin >> x >> y >> a >> b;
  if (a == b && a == x) {
    cout << 0;
    return 0;
  }
  if (a == b) a += 1;
  if (a > b) s.insert(make_pair(a, b));
  for (int j = b; j <= y; j++) {
    for (int i = a + 1; i <= x; i++) {
      if (i > j) s.insert(make_pair(i, j));
    }
  }
  cout << s.size() << endl;
  set<pair<int, int> >::iterator it = s.begin();
  while (it != s.end()) {
    cout << it->first << " " << it->second << endl;
    it++;
  }
}
