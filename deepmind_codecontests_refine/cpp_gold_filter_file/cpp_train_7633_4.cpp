#include <bits/stdc++.h>
using namespace std;
pair<long long, long long> a[1000001], wx[1000001];
long long w[1000001];
void count(long long x, long long y, long long &tt) {
  long long tmx = tt, j = 0;
  if (a[y].first > tmx) tmx = a[y].first;
  for (int i = (x); i <= (y); i++) wx[j++] = make_pair(a[i].second, i);
  sort(wx, wx + j);
  for (int i = 0; i < (j - 1); i++) {
    long long k = 0;
    tmx += wx[i].first - ((i) ? wx[i - 1].first : 0);
    if (wx[i].first == wx[i + 1].first) {
      while (i < j - 1 && wx[i].first == wx[i + 1].first) {
        ++k;
        w[wx[i].second] = tmx;
        ++i;
      }
      w[wx[i].second] = tmx;
      ++k;
      tmx += 1 + k / 2;
    } else {
      w[wx[i].second] = tmx;
      ++k;
      tmx += 1 + k / 2;
    }
  }
  if (j == 1 || wx[j - 1].first != wx[j - 2].first) {
    tmx += wx[j - 1].first - ((j > 1) ? wx[j - 2].first : 0);
    w[wx[j - 1].second] = tmx;
    ++tmx;
  }
  tmx += wx[j - 1].first;
  tt = tmx;
}
int main() {
  long long n, m;
  cin >> n >> m;
  for (int i = 1; i <= (n); i++) cin >> a[i].first >> a[i].second;
  long long k = 1, tt = 0;
  while (m * k <= n) {
    count(m * (k - 1) + 1, m * k, tt);
    ++k;
  }
  if (m * (k - 1) != n) count(m * (k - 1) + 1, n, tt);
  for (int i = 1; i <= (n); i++) cout << w[i] << ' ';
  return 0;
}
