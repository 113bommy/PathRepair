#include <bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC target("avx,avx2,fma")
#pragma GCC optimization("unroll-loops")
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int h = 0;
  cin >> h;
  vector<int> a(h + 1);
  int ok = -1, am = 0;
  for (int i = 0; i < h + 1; i++) {
    cin >> a[i];
    am += a[i];
    if (i && a[i] > 1 && a[i - 1] > 1) ok = 1;
  }
  if (ok == -1) {
    cout << "perfect\n";
    return 0;
  }
  cout << "ambiguous\n";
  int left = 1, cur = 0, cpos = 0;
  for (int i = 0; i < am; i++) {
    cout << cur << ' ';
    left--;
    if (left == 0) {
      left = a[++cpos];
      cur = i + 1;
    }
  }
  cout << endl;
  bool u = false;
  left = 1, cur = 0, cpos = 0;
  for (int i = 0; i < am; i++) {
    cout << cur << ' ';
    left--;
    if (!u && cpos && a[cpos - 1] > 1 && a[cpos] > 1) {
      u = true;
      cur--;
    }
    if (!left) {
      left = a[++cpos];
      cur = i + 1;
    }
  }
  return 0;
}
