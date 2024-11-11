#include <bits/stdc++.h>
using namespace std;
int s[200005];
int p[200005];
int main() {
  int n, d, final;
  cin >> n >> d;
  for (int i = 1; i <= n; i++) cin >> s[i];
  for (int i = 1; i <= n; i++) cin >> p[i];
  s[d] += p[1];
  set<int, greater<int> > st;
  for (int i = n - d + 2, j = 1; i <= n and j < d; i++, j++) st.insert(p[i]);
  final = d;
  for (int i = d - 1; i >= 1; i++) {
    auto it = st.lower_bound(s[d] - s[i]);
    if (it == st.end())
      break;
    else
      st.erase(it), final--;
  }
  cout << final << endl;
}
