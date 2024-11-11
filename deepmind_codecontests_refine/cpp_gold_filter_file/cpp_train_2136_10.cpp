#include <bits/stdc++.h>
using namespace std;
class C_ {};
template <typename T>
C_& operator<<(C_& __m, const T& __s) {
  if (!1) cerr << "\E[91m" << __s << "\E[0m";
  return __m;
}
C_ merr;
struct __s {
  __s() {
    if (1) {
      ios_base::Init i;
      cin.sync_with_stdio(0);
      cin.tie(0);
    }
  }
  ~__s() {
    merr << "Execution time: " << (double)clock() / CLOCKS_PER_SEC << " s.\n";
  }
} __S;
string a, b;
bool bad(char c1, char c2) {
  return (c1 == 'N' && c2 == 'S') || (c1 == 'S' && c2 == 'N') ||
         (c1 == 'W' && c2 == 'E') || (c1 == 'E' && c2 == 'W');
}
int main(void) {
  int idx1 = 0, idx2 = 0;
  int cnt = 0;
  int n;
  cin >> n;
  cin >> a >> b;
  while ((idx1 < (int)a.size() || idx2 < (int)b.size()) && cnt < 50) {
    while (idx1 < (int)a.size()) {
      if (idx2 && bad(a[idx1], b[idx2 - 1])) {
        idx2--;
      } else if (idx2 < (int)b.size() && a[idx1] == b[idx2]) {
        idx2++;
      }
      idx1++;
      if (idx2 < (int)b.size() && !bad(b[idx2], a[idx1 - 1])) {
        idx2++;
      }
    }
    swap(idx1, idx2);
    swap(a, b);
    cnt++;
  }
  if (cnt >= 50) {
    cout << "NO" << '\n';
  } else {
    cout << "YES" << '\n';
  }
  return 0;
}
