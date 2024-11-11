#include <bits/stdc++.h>
using namespace std;
const long long M = 1e9 + 7;
vector<pair<int, int>> v;
bool cmp(pair<int, int> a, pair<int, int> b) { return a.second < b.second; }
bool cmp1(pair<int, int> a, pair<int, int> b) {
  if (a.first == b.first) return a.second > b.second;
  return a.first < b.first;
}
int main() {
  int n;
  cin >> n;
  for (int i = 1; i < 10; i++) {
    int x;
    cin >> x;
    v.push_back(make_pair(x, i));
  }
  sort(v.begin(), v.end(), cmp1);
  int l = n / v[0].first;
  if (l == 0) {
    cout << -1;
    return 0;
  }
  string s;
  for (int i = 0; i < l; i++) {
    char ch;
    ch = v[0].second + '0';
    s.push_back(ch);
  }
  if (v[0].second == 9) {
    cout << s;
    return 0;
  }
  int a = v[0].second;
  int k = 0;
  int sum = n % v[0].first;
  sort(v.begin(), v.end(), cmp);
  for (int i = 8; i >= a; i--) {
    if (k >= s.size()) break;
    if (sum >= abs(v[i].first - v[a - 1].first)) {
      char ch;
      ch = v[i].second + '0';
      s[k] = ch;
      k++;
      sum -= v[i].first - v[a - 1].first;
      i++;
    }
  }
  cout << s;
}
