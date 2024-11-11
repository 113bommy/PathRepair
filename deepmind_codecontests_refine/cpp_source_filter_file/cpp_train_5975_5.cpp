#include <bits/stdc++.h>
using namespace std;
struct pos {
  int s, a, b;
  int nr;
};
bool porownanie(pos a, pos b) {
  if (a.s < b.s) return true;
  return false;
}
bool porownanie2(pos a, pos b) {
  if (a.nr < b.nr) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<pos> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i].s;
    a[i].nr = i;
  }
  sort(a.begin(), a.end(), porownanie);
  int blok = n / 3;
  if (n % 3 != 0) ++blok;
  for (int i = 0; i < blok; ++i) {
    a[i].a = i;
    a[i].b = a[i].s - i;
  }
  for (int i = blok; i < 2 * blok; ++i) {
    a[i].b = i;
    a[i].a = a[i].s - i;
  }
  for (int i = n - 1; i >= 2 * blok; --i) {
    a[i].b = (n - 1) - i;
    a[i].a = a[i].s - ((n - 1) - i);
  }
  sort(a.begin(), a.end(), porownanie2);
  cout << "Yes" << endl;
  for (int i = 0; i < n; ++i) cout << a[i].a << " ";
  cout << endl;
  for (int i = 0; i < n; ++i) cout << a[i].b << " ";
  return 0;
}
