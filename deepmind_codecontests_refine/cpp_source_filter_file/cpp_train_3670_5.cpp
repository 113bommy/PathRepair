#include <bits/stdc++.h>
using namespace std;
pair<int, int> GetPii(int x, int y) {
  if (x > y) swap(x, y);
  return pair<int, int>(x, y);
}
int main() {
  int T;
  cin >> T;
  while (T--) {
    int n;
    scanf("%d", &n);
    vector<int> a(n);
    for (int& x : a) scanf("%d", &x);
    vector<int> b(n);
    for (int& x : b) scanf("%d", &x);
    bool Ok = true;
    if (n & 1) Ok &= (a[n / 2] == b[n / 2]);
    map<pair<int, int>, int> Cnt;
    for (int i = 0, j = n - 1; i < j; j--, i++) Cnt[GetPii(b[i], b[j])]++;
    for (int i = 0, j = n - 1; i < j; j--, i++) {
      Ok &= Cnt[GetPii(a[i], a[j])];
      Cnt[GetPii(a[i], a[j])]--;
    }
    puts(Ok ? "Yes" : "No");
  }
}
