#include <bits/stdc++.h>
using namespace std;
int n, d = 0;
pair<int, int> a[110];
void nhap() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i].first >> a[i].second;
}
int main() {
  nhap();
  for (int i = 1; i <= n; i++)
    if (a[i].second - a[i].first > 0) d++;
  cout << d;
  return 0;
}
