#include <bits/stdc++.h>
using namespace std;
const int SABET = 1200;
bool f(pair<int, pair<int, int> > a, pair<int, pair<int, int> > b) {
  if (a.first / SABET == b.first / SABET)
    return a.second.first < b.second.first;
  return a.first < b.first;
}
int main() {
  int n;
  scanf("%d", &n);
  pair<int, pair<int, int> > a[n];
  int x, y;
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &x, &y);
    a[i].first = x;
    a[i].second.first = y;
    a[i].second.second = i + 1;
  }
  sort(a, a + n, f);
  for (int i = 0; i < n; i++) {
    printf("%d ", a[i].second.second);
  }
}
