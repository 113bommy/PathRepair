#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  multiset<long long> st;
  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    st.insert(a);
  }
  long long ans = 0;
  bool first = true;
  while (st.size() > 1) {
    long long sm = 0;
    for (int i = 0; i < 3; i++) {
      sm += *(st.begin());
      st.erase(st.begin());
      if (first && n % 2 == 0 && i == 1) {
        first = false;
        break;
      }
      if (st.empty()) break;
    }
    ans += sm;
    st.insert(sm);
  }
  cout << ans << endl;
}
