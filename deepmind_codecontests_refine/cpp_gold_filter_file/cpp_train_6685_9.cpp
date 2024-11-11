#include <bits/stdc++.h>
using namespace std;
long long gcd(long long a, long long b) { return b ? gcd(b, a % b) : a; }
long long lcm(long long a, long long b) { return a * b / gcd(a, b); }
const int maxn = 2e5 + 5;
struct H {
  int x;
  int flag;
} s[maxn << 1];
bool cmp(const H& a, const H& b) {
  if (a.x < b.x) return true;
  if (a.x == b.x) return a.flag > b.flag;
  return false;
}
set<int> st;
int only[maxn];
int main() {
  ios::sync_with_stdio(false), cin.tie(NULL);
  ;
  int t;
  cin >> t;
  while (t--) {
    st.clear();
    memset((only), (0), sizeof(only));
    int n, cnt = 0;
    cin >> n;
    for (int i = (1); i <= (n); i++) {
      int x, y;
      cin >> x >> y;
      s[++cnt].x = x;
      s[cnt].flag = i;
      s[++cnt].x = y;
      s[cnt].flag = -i;
    }
    sort(s + 1, s + cnt + 1, cmp);
    int ans = 0;
    for (int i = (1); i <= (cnt); i++) {
      if (s[i].flag > 0) {
        if (st.empty()) only[abs(s[i].flag)]--;
        st.insert(abs(s[i].flag));
      } else {
        st.erase(abs(s[i].flag));
        if (st.empty()) only[abs(s[i].flag)]--, ans++;
      }
      if (st.size() == 1) only[*st.begin()]++;
    }
    int MAX = -1;
    for (int i = (1); i <= (n); i++) MAX = max(only[i], MAX);
    cout << ans + MAX << "\n";
  }
  return 0;
}
