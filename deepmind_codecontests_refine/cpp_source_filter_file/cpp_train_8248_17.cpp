#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    set<long long> st;
    for (long long i = 0; i < n; i++) {
      long long temp;
      cin >> temp;
      st.insert(temp);
    }
    bool flag = false;
    long long val = -1;
    for (long long i = 0; i <= 1024; i++) {
      for (auto it : st) {
        if (st.find(it ^ i) != st.end()) {
          continue;
        } else {
          flag = true;
          break;
        }
      }
      if (flag) {
        flag = false;
        continue;
      } else {
        val = i;
        break;
      }
    }
    cout << val << "\n";
  }
  return 0;
}
