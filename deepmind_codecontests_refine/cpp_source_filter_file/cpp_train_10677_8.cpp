#include <bits/stdc++.h>
using namespace std;
const int mod = int(1e9) + 7;
const int MX = 3050;
char z[MX][MX];
pair<int, int> a[MX];
void go(int u, int v, int r) {
  if (r == 0)
    z[u][v] = z[v][u] = 'D';
  else if (r == -1) {
    z[u][v] = 'W';
    z[v][u] = 'L';
  } else {
    z[u][v] = 'L';
    z[v][u] = 'W';
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  int n, m;
  cin >> m >> n;
  int s = m * (m - 1);
  for (int i = 0; i < n; i++) {
    cin >> a[i].first;
    s -= a[i].first;
    a[i].second = i;
  }
  if (s < 0) {
    puts("no");
    return 0;
  }
  int k = m - n;
  for (int i = n; i < m; i++) {
    a[i].first = s / k;
    if (s % k) a[i].first++;
    s -= a[i].first;
    k--;
    a[i].second = i;
  }
  if (s) {
    puts("no");
    return 0;
  }
  for (int i = 1; i < m; i++) {
    if (a[i].first > a[i - 1].first) {
      puts("no");
      return 0;
    }
  }
  reverse(a, a + m);
  for (int i = m - 1; i >= 0; i--) {
    int j = i - 1;
    a[i].first = i * 2 - a[i].first;
    if (a[i].first < 0) {
      puts("no");
      return 0;
    }
    while (j >= 0 && a[i].first > 1) {
      j--;
      a[i].first -= 2;
    }
    if (j < 0 && a[i].first > 0) {
      puts("no");
      return 0;
    }
    int p = j + 1;
    if (a[i].first) {
      j--;
      a[i].first--;
    }
    while (p < i && j >= 0 && a[p].first == a[j].first) {
      j--;
      p++;
    }
    for (int q = p; q < i; q++) {
      go(a[i].second, a[q].second, -1);
      a[q].first -= 2;
    }
    for (int q = j + 1; q < p; q++) {
      go(a[i].second, a[q].second, 0);
      a[q].first--;
    }
    for (int q = 0; q <= j; q++) {
      go(a[i].second, a[q].second, -1);
    }
    sort(a, a + i);
  }
  puts("yes");
  for (int i = 0; i < m; i++) {
    z[i][i] = 'X';
    z[i][m] = '\0';
    puts(z[i]);
  }
  return 0;
}
