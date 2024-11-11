#include <bits/stdc++.h>
using namespace std;
set<int> st;
int n;
int arr[100000];
int ans[100000];
map<int, int> ind;
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    ind[arr[i]] = i;
    if (st.size() < 2) {
      st.insert(arr[i]);
      if (i > 0)
        ans[i] = ans[i - 1] + 20;
      else
        ans[i] = 20;
      cout << 20 << endl;
    } else {
      st.insert(arr[i]);
      ans[i] = ans[i - 1] + 20;
      int tmp = 20;
      int b = *st.upper_bound(max(0, arr[i] - 90));
      int ii = ind[b];
      int prev = 0;
      if (ii > 0) {
        prev = ans[ii - 1];
      }
      if (50 - (ans[i - 1] - prev) < tmp) {
        tmp = 50 - (ans[i - 1] - prev);
        ans[i] = prev + 50;
      }
      b = *st.upper_bound(max(0, arr[i] - 1440));
      ii = ind[b];
      prev = 0;
      if (ii > 0) {
        prev = ans[ii - 1];
      }
      if (120 - (ans[i - 1] - prev) < tmp) {
        tmp = 120 - (ans[i - 1] - prev);
        ans[i] = prev + 120;
      }
      cout << tmp << endl;
    }
  }
  return 0;
}
