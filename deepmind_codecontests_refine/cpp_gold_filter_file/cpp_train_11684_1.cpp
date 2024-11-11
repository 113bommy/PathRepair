#include <bits/stdc++.h>
using namespace std;
template <typename _T>
inline void _DBG(const char *s, _T x) {
  cerr << s << " = " << x << "\n";
}
template <typename _T, typename... args>
void _DBG(const char *s, _T x, args... a) {
  while (*s != ',') cerr << *s++;
  cerr << " = " << x << ',';
  _DBG(s + 1, a...);
}
int arr[107];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  ;
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    int indx = -1;
    for (int i = 1; i < n + 1; i++) {
      cin >> arr[i];
      if ((arr[i] & 1) == 0) {
        indx = i;
      }
    }
    if (indx == -1) {
      if (n == 1) {
        cout << -1 << "\n";
      } else {
        cout << 2 << "\n" << 1 << " " << 2 << "\n";
      }
    } else {
      cout << 1 << "\n" << indx << "\n";
    }
  }
}
