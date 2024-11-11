#include <bits/stdc++.h>
using namespace std;
using namespace std;
int k;
string ad;
vector<string> c(string s) {
  vector<string> ans;
  int last = 0;
  for (long long i = 0; i < (s.size()); i++) {
    if (s[i] == ' ' || s[i] == '-' || i == s.size() - 1) {
      ans.push_back(s.substr(last, i - last + 1));
      last = i + 1;
    }
  }
  return ans;
}
vector<string> v;
bool check(int mid) {
  int nlen = 0;
  int cnt = 1;
  for (long long i = 0; i < (v.size()); i++) {
    if (v[i].size() > mid) {
      return false;
    }
    if (nlen + v[i].size() <= mid) {
      nlen += v[i].size();
    } else {
      nlen = v[i].size();
      cnt++;
    }
  }
  if (cnt <= k) {
    return true;
  }
  return false;
}
int main() {
  cin >> k;
  cin.ignore();
  getline(cin, ad, '\n');
  v = c(ad);
  int l = 0, r = ad.size();
  while (l < r) {
    int mid = (l + r) >> 1;
    if (!check(mid)) {
      l = mid + 1;
    } else {
      r = mid;
    }
  }
  cout << r;
  return 0;
}
