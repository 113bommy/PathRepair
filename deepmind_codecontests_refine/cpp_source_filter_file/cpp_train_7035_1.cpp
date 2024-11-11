#include <bits/stdc++.h>
using namespace std;
string s, t;
bool check(string temp, string t, int k) {
  bool ok = true;
  int j = 0;
  for (int i = 0; i < s.size(); i++) {
    if (temp[i] == t[j]) j++;
  }
  if (j == t.size()) return true;
  return false;
}
int main() {
  cin >> s >> t;
  int n = s.size();
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i], v[i]--;
  int low = 0;
  int high = n;
  int mid = (low + high) / 2;
  while (high - low > 1) {
    string temp = s;
    for (int i = 0; i <= mid; i++) temp[v[i]] = '@';
    if (check(temp, t, mid)) {
      low = mid;
    } else {
      high = mid;
    }
    mid = (low + high) / 2;
  }
  string temp = s;
  for (int i = 0; i <= high; i++) {
    temp[v[i]] = '@';
  }
  cout << low + 1;
}
