#include <bits/stdc++.h>
using namespace std;
bool com(pair<long long int, long long int> a,
         pair<long long int, long long int> b) {
  if (a.first > b.first) return true;
  return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  vector<long long int> num(s.size());
  vector<long long int> eve;
  bool flag = false;
  long long int sw = INT_MIN;
  for (long long int i = 0; i < s.size(); i++) {
    long long int n = (s[i] - '0');
    long long int l = (s[s.size() - 1] - '0');
    if (n % 2 == 0) {
      if (l > n) {
        sw = max(sw, i);
      }
      eve.push_back(i);
      flag = true;
    }
    num[i] = n;
  }
  if (flag) {
    if (sw == INT_MIN) sw = *max_element(eve.begin(), eve.end());
    swap(num[sw], num[s.size() - 1]);
    for (long long int i = 0; i < s.size(); i++) cout << num[i];
  } else {
    cout << "-1";
  }
  cout << "\n";
  return 0;
}
