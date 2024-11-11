#include <bits/stdc++.h>
using namespace std;
int gcd(int a, int b) {
  if (b == 0)
    return a;
  else
    return gcd(b, a % b);
}
bool mycmp(pair<long long, long long> a, pair<long long, long long> b) {
  return a.second > b.second;
}
bool cmp(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first)
    return a.second < b.second;
  else
    return a.first > b.first;
}
int main() {
  int n;
  cin >> n;
  int M = 1e9 + 7;
  long long a = 1, b = 1;
  for (int i = 0; i < 3 * n; i++) a = (a * 3) % M;
  for (int i = 0; i < n; i++) b = (b * 7) % M;
  cout << (a - b + M) % M;
  return 0;
}
