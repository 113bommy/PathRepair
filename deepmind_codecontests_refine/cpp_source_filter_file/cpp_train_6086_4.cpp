#include <bits/stdc++.h>
using namespace std;
int n, t;
int s[100013];
int g[17][100013];
int lg[100013];
vector<pair<int, int> > sorted;
int gcd(int a, int b) { return (b == 0) ? a : gcd(b, a % b); }
int find_l(int gcf, int ind) {
  int left = 0, right = sorted.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (sorted[mid].first < gcf ||
        (sorted[mid].first == gcf && sorted[mid].second < ind)) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return (left + right) / 2;
}
int find_r(int gcf, int ind) {
  int left = 0, right = sorted.size() - 1;
  while (left < right) {
    int mid = (left + right) / 2;
    if (sorted[mid].first > gcf ||
        (sorted[mid].first == gcf && sorted[mid].second > ind)) {
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return (left + right) / 2;
}
int query(int l, int r) {
  int tmp = l;
  int gcf = 0;
  for (int i = 16; i >= 0; i--)
    if ((r - l + 1) & (1 << i)) {
      gcf = gcd(gcf, g[i][l]), l = l + (1 << i);
    }
  l = tmp;
  return r - l + 1 - max(0, find_r(gcf, r) - find_l(gcf, l));
}
int main() {
  scanf("%d", &n);
  int l = 0;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &s[i]);
    sorted.push_back(make_pair(s[i], i));
    if (i == (1 << (l + 1))) l++;
    lg[i] = l;
  }
  sort(sorted.begin(), sorted.end());
  for (int i = 1; i <= n; i++) {
    g[0][i] = s[i];
  }
  for (int i = 1; i <= 16; i++) {
    for (int j = 1; j <= n; j++) {
      g[i][j] = gcd(g[i - 1][j], g[i - 1][min(n, j + (1 << (i - 1)))]);
    }
  }
  scanf("%d", &t);
  for (int i = 0; i < t; i++) {
    int l, r;
    scanf("%d%d", &l, &r);
    printf("%d\n", query(l, r));
  }
}
