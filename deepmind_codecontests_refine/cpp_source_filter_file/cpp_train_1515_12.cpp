#include <bits/stdc++.h>
using namespace std;
const double EPS = 1e-8;
const double PI = acos(-1.0);
const int oo = 0x3f3f3f3f;
long long read() {
  long long d, f = 1;
  char c;
  while (!isdigit(c = getchar()))
    if (c == '-') f = -1;
  d = c ^ '0';
  while (isdigit(c = getchar())) d = (d * 10) + (c ^ '0');
  return d * f;
}
int main() {
  map<int, int> mp;
  for (int i = 0; i < 5; ++i) mp[read()]++;
  int sum = 0;
  for (auto it : mp) sum += it.first * it.second;
  int MAX = -oo;
  for (auto it : mp)
    if (it.second > 1) MAX = max(MAX, it.first * min(3, it.second));
  cout << sum - MAX << endl;
  return 0;
}
