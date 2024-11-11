#include <bits/stdc++.h>
using namespace std;
vector<int> v;
void sieve(long long n) {
  int arr[n + 1];
  memset(arr, -1, sizeof(arr));
  for (int i = 2; i * i <= n; i++) {
    if (arr[i] == -1) {
      for (int j = i * i; j <= n; j += i) arr[j] = 1;
    }
  }
  for (int i = 2; i < n + 1; i++) {
    if (arr[i] == -1) v.push_back(i);
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long t;
  t = 1;
  while (t--) {
    string s;
    cin >> s;
    unordered_map<char, int> mp;
    char c;
    int maxi = INT_MIN;
    for (int i = 0; i < s.length(); i++) {
      mp[s[i]]++;
      if (mp[s[i]] > maxi) {
        maxi = mp[s[i]];
        c = s[i];
      }
    }
    sieve(s.length());
    v.push_back(-1);
    string ans(s.length(), '0');
    int j = 0;
    int f = 1;
    for (int i = 1; i < s.length() + 1; i++) {
      if (i == 1) continue;
      if (i == v[j]) {
        j++;
        if (s.length() / i == 1) continue;
      }
      if (mp[c] == 0) {
        f = 0;
        break;
      }
      ans[i - 1] = c;
      mp[c]--;
    }
    if (f) {
      stack<char> st;
      for (auto j : mp) {
        int temp = j.second;
        while (temp--) st.push(j.first);
      }
      for (int i = 0; i < s.length(); i++) {
        if (ans[i] == '0') {
          ans[i] = st.top();
          st.pop();
        }
      }
      cout << "YES" << '\n';
      cout << ans << '\n';
    } else
      cout << "NO" << '\n';
  }
  return 0;
}
