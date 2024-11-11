#include <bits/stdc++.h>
using namespace std;
const long long INF = 1e17 + 9;
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int t[100009];
  int vet[100009];
  for (long long i = 0; i < (n); ++i) {
    cin >> vet[i];
  }
  stack<int> st;
  st.push(vet[0]);
  t[0] = -1;
  int ans = 0;
  for (long long i = 1; i < (n); ++i) {
    t[i] = 0;
    while ((long long)(st).size() > 0 && vet[i] > vet[st.top()]) {
      t[i] = max(t[i], t[st.top()] + 1);
      st.pop();
    }
    if ((long long)(st).size() == 0) {
      t[i] = -1;
    }
    st.push(i);
    ans = max(ans, t[i] + 1);
  }
  cout << ans << "\n";
  return 0;
}
