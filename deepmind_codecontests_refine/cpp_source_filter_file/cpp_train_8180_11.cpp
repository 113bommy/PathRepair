#include <bits/stdc++.h>
using namespace std;
void read(long long &x) { scanf("%lld", &x); }
void print(long long x) { printf("%lld ", x); }
void println(long long x) { printf("%lld\n", x); }
long long n;
pair<long long, long long> a[22] = {
    {1, 8}, {3, 5}, {2, 7}, {4, 6}, {3, 6}, {4, 5}, {2, 8}, {1, 7},
    {1, 6}, {4, 8}, {3, 7}, {2, 5}, {2, 6}, {3, 8}, {1, 5}, {4, 7}};
pair<long long, long long> b[22] = {{3, 6}, {4, 9}, {3, 9}, {1, 8}, {3, 5},
                                    {2, 5}, {1, 5}, {1, 9}, {3, 8}, {2, 8},
                                    {2, 6}, {4, 7}, {2, 7}, {2, 9}, {4, 6},
                                    {4, 5}, {4, 8}, {1, 6}, {3, 7}, {1, 7}};
pair<long long, long long> c[22] = {{2, 4}, {3, 4}, {1, 2},
                                    {1, 4}, {2, 3}, {1, 3}};
pair<long long, long long> d[22] = {{1, 4}, {3, 5}, {2, 5}, {1, 2}, {1, 3},
                                    {2, 3}, {4, 5}, {2, 4}, {1, 5}, {3, 4}};
void out(long long l, long long r) {
  if (n - r == 5)
    for (long long i = 0; i < 20; i++)
      print(b[i].first + l), println(b[i].second + r);
  else
    for (long long i = 0; i < 16; i++)
      print(a[i].first + l), println(a[i].second + r);
}
void output(long long l) {
  if (n - l == 5)
    for (long long i = 0; i < 10; i++)
      print(d[i].first + l), println(d[i].second + l);
  else
    for (long long i = 0; i < 6; i++)
      print(c[i].first + l), println(c[i].second + l);
}
int main() {
  cin >> n;
  if (n % 4 > 1) {
    cout << "NO";
    return 0;
  }
  cout << "YES\n";
  for (long long i = 1; i < n / 4; i++)
    for (long long j = i + 1; j <= n / 4; j++) out((i - 1) * 4, (j - 1) * 4);
  for (long long i = 1; i <= n / 4; i++) output((i - 1) * 4);
}
