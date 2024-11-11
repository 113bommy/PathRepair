#include <bits/stdc++.h>
using namespace std;
int main() {
  set<int> st;
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long n, k;
  cin >> n >> k;
  st.insert(1);
  st.insert(n);
  for (int i = 2; i <= sqrt(n); i++) {
    if (n % i == 0) {
      st.insert(i);
      st.insert(n / i);
    }
  }
  if (st.size() < k) cout << -1 << endl, exit(0);
  int i = 1;
  auto itr = st.begin();
  while (itr != st.end()) {
    if (i == k) cout << *itr << endl;
    i++;
    itr++;
  }
  return 0;
}
