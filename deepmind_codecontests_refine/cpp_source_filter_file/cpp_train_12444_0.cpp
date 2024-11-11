#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<pair<int, int> > v;
  string s;
  int n = 0;
  getline(cin, s);
  int semn = 0;
  for (auto c : s) {
    if (c == ' ') continue;
    if (c == '+')
      semn = 0;
    else if (c == '-')
      semn = 1;
    else if (c == '?')
      v.push_back(make_pair(semn, 1));
    else if (c >= '0' && c <= '9')
      n = n * 10 + c - '0';
  }
  int sum = 0;
  for (auto c : v) {
    if (c.first == 0)
      sum++;
    else
      sum--;
  }
  for (auto &c : v) {
    if (c.first == 0) {
      if (sum < n) {
        int add = min(n - 1, n - sum);
        sum += add;
        c.second += add;
      }
    }
    if (c.first == 1) {
      if (sum > n) {
        int sub = min(n - 1, sum - n);
        sum -= sub;
        c.second -= sub;
      }
    }
  }
  if (sum != n)
    cout << "Impossible";
  else {
    cout << "Possible\n";
    for (int i = 0; i < v.size(); i++) {
      if (i == 0)
        cout << v[i].second << " ";
      else {
        if (v[i].first == 0)
          cout << "+ ";
        else
          cout << "- ";
        cout << v[i].second << " ";
      }
    }
    cout << "= " << n;
  }
  return 0;
}
