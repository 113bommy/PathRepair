#include <bits/stdc++.h>
using namespace std;
int n;
unsigned a[100500];
set<unsigned> st;
void solve(unsigned mask) {
  cout << (mask >> 24) << "." << ((mask << 8) >> 24) << "."
       << ((mask << 16) >> 24) << "." << ((mask << 24) >> 24) << endl;
}
int k;
int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> k;
  unsigned part[4];
  char tmp;
  for (int i = 0; i < n; i++) {
    cin >> part[0];
    for (int j = 1; j < 4; j++) {
      cin >> tmp >> part[j];
    }
    int ans = 0;
    for (int j = 0; j < 4; j++) {
      ans += part[j] << (8 * (3 - j));
    }
    a[i] = ans;
  }
  unsigned mask = 0;
  for (int i = 31; i >= 0; i--) {
    mask |= (unsigned)1 << i;
    st.clear();
    for (int j = 0; j < n; j++) {
      st.insert(a[j] & mask);
    }
    if (st.size() == k) {
      solve(mask);
      return 0;
    }
  }
  cout << -1;
  return 0;
}
