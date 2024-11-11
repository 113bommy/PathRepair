#include <bits/stdc++.h>
using namespace std;
void da(int *a, int s, int e) {
  for (int i = s; i < e; i++) cout << a[i] << " ";
}
void db(string s) { cout << s << '\n'; }
void cp(int *a, int *b, int n) {
  for (int i = 0; i < n; i++) b[i] = a[i];
}
void de(int a) { cout << a << " <\n"; }
const int N = 1e5 + 10, sq = 400;
int n, m, t, x, a[N], b[N];
string s;
set<int> st;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x;
    st.insert(x);
    auto it = st.upper_bound(x);
    if (it != st.end()) st.erase(it);
  }
  cout << st.size() << '\n';
  return 0;
}
