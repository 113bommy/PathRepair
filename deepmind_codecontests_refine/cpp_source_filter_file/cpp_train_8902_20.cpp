#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  char arCh[n];
  long long int arIn[n];
  for (int i = 0; i < n; i++) {
    cin >> arCh[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> arIn[i];
  }
  int k = 0;
  set<int> st;
  while (k >= 0 && k <= n) {
    if (st.count(k)) {
      cout << "INFINITE";
      return 0;
    }
    st.insert(k);
    if (arCh[k] == '>')
      k += arIn[k];
    else
      k -= arIn[k];
  }
  cout << "FINITE";
}
