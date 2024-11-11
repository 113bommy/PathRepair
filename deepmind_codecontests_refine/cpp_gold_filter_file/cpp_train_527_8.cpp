#include <bits/stdc++.h>
using namespace std;
int fun(string str, int n, int k) {
  set<char> st;
  for (int i = 0; i < n; i++) {
    st.insert(str[i]);
  }
  string s = "";
  for (auto i : st) {
    s = s + (i);
  }
  sort(s.begin(), s.end());
  if (k > 26) return -1;
  if (n >= 1 && k == 1) return 1 + (s[0] - 'a');
  int sum = 0, i, count = 0;
  for (i = 0; i < s.size() - 1; i++) {
    if (s[i + 1] - s[i] == 1) {
      sum = sum + (s[i] - 'a') + 1;
      count++;
      i++;
      if (k == count) return sum;
      continue;
    }
    if (s[i + 1] - s[i] > 1) {
      sum = sum + (s[i] - 'a') + 1;
      count++;
    }
    if (k == count) return sum;
  }
  if (k > count && s[s.size() - 1] - s[s.size() - 2] > 1) {
    sum = sum + (s[s.size() - 1] - 'a') + 1;
    count++;
  }
  if (k == count) return sum;
  return -1;
}
int main() {
  int n, k, i, j;
  string s;
  cin >> n >> k;
  cin >> s;
  cout << fun(s, n, k);
}
