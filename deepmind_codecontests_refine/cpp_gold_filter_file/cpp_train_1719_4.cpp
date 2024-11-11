#include <bits/stdc++.h>
using namespace std;
bool cmp(pair<long long int, char> p1, pair<long long int, char> p2) {
  return p1.first > p2.first;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  string s;
  cin >> s;
  stack<long long int> st;
  long long int i, n = s.size();
  long long int arr[n][2];
  for (i = 0; i < n; i++) {
    arr[i][0] = -1;
    arr[i][1] = -1;
    if (s[i] == '(')
      st.push(i);
    else {
      if (st.empty()) {
        arr[i][0] = -1;
        arr[i][1] = -1;
      } else {
        arr[i][0] = st.top();
        st.pop();
        if (arr[i][0] == 0 or
            (s[arr[i][0] - 1] == '(' or arr[arr[i][0] - 1][1] == -1))
          arr[i][1] = arr[i][0];
        else
          arr[i][1] = arr[arr[i][0] - 1][1];
      }
    }
  }
  long long int m = INT_MIN;
  for (i = 0; i < n; i++) {
    if (arr[i][1] != -1 and i - arr[i][1] + 1 > m) m = i - arr[i][1] + 1;
  }
  long long int ans = 0;
  for (i = 0; i < n; i++) {
    if (arr[i][1] != -1 and i - arr[i][1] + 1 == m) ans++;
  }
  if (m == INT_MIN)
    cout << "0 1"
         << "\n";
  else
    cout << m << " " << ans << "\n";
}
