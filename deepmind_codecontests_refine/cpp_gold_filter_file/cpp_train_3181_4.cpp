#include <bits/stdc++.h>
using namespace std;
template <class _T>
inline _T sqr(const _T& x) {
  return x * x;
}
template <class _T>
inline string tostr(const _T& a) {
  ostringstream os("");
  os << a;
  return os.str();
}
const long double PI = 3.1415926535897932384626433832795;
const long double EPS = 1e-11;
int n, k;
int a[102400];
multiset<int> d;
int ans[102400][2];
int cnt;
int main() {
  cout << setiosflags(ios::fixed) << setprecision(10);
  scanf("%d%d", &n, &k);
  for (int i = 0; i < (int)(n); i++) {
    scanf("%d", a + i);
  }
  int j = 0;
  int ma = -1;
  cnt = 0;
  for (int i = 0; i < (int)(n); i++) {
    d.insert(a[i]);
    __typeof(d.begin()) it1 = d.begin(), it2 = d.end();
    it2--;
    while (*it2 - *it1 > k) {
      d.erase(d.find(a[j++]));
      it1 = d.begin(), it2 = d.end();
      it2--;
    }
    if (i - j + 1 > ma) {
      ma = i - j + 1;
      cnt = 0;
      ans[cnt][0] = j;
      ans[cnt][1] = i;
      cnt++;
    } else if (i - j + 1 == ma) {
      ans[cnt][0] = j;
      ans[cnt][1] = i;
      cnt++;
    }
  }
  printf("%d %d\n", ma, cnt);
  for (int i = 0; i < (int)(cnt); i++) {
    printf("%d %d\n", ans[i][0] + 1, ans[i][1] + 1);
  }
  return 0;
}
