#include <bits/stdc++.h>
using namespace std;
void bug() { cout << " " << endl; }
template <class T>
void bug(T a) {
  cout << a << "  ";
}
template <class T>
void bug(T* a, int n) {
  for (int i = 0; i < (n); i++) bug(a[i]);
}
int n;
pair<int, int> p[1111111];
int o[111111];
int cmp(int x, int y) { return p[x] < p[y]; }
void run() {
  cin >> n;
  for (int i = 0; i < (2 * n - 1); i++) cin >> p[i].first >> p[i].second;
  for (int i = 0; i < (2 * n - 1); i++) o[i] = i;
  sort(o, o + 2 * n - 1, cmp);
  long long even = 0, odd = 0;
  for (int i = 0; i < (2 * n - 2); i++) {
    if (i % 2 == 0)
      even += p[o[i]].second;
    else
      odd += p[o[i]].second;
  }
  cout << "YES" << endl;
  if (even > odd) {
    for (int i = 0; i < 2 * n - 2; i += 2) cout << o[i] + 1 << " ";
    cout << o[2 * n - 2] + 1 << endl;
  } else {
    for (int i = 1; i < 2 * n - 2; i += 2) cout << o[i] + 1 << " ";
    cout << o[2 * n - 2] + 1 << endl;
  }
}
int main() {
  int t;
  cin >> t;
  while (t--) run();
  return 0;
}
