#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:667177216")
const long long mod = 1000000007;
using namespace std;
struct seg {
  int l, r, idx;
};
bool cmp(seg a, seg b) {
  if (a.l < b.l) return true;
  if (a.l > b.l) return false;
  if (b.r - b.l < a.r - a.l) return true;
  return false;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<seg> mas(n);
  for (int i = 0; i < n; i++) {
    cin >> mas[i].l >> mas[i].r;
    mas[i].idx = i;
  }
  sort((mas).begin(), (mas).end(), cmp);
  for (int i = 0; i < n - 1; i++) {
    if (mas[i + 1].l >= mas[i].l && mas[i + 1].r <= mas[i].r) {
      cout << mas[i].idx + 1 << ' ' << mas[i + 1].idx + 1;
      return 0;
    }
  }
  cout << "-1 -1";
  return 0;
}
