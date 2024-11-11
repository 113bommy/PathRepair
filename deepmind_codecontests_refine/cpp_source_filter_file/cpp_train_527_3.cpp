#include <bits/stdc++.h>
using namespace std;
bool SortbySecDesc(const pair<long long, long long> &a,
                   const pair<long long, long long> &b) {
  return a.second > b.second;
}
bool sortinrev(const pair<int, int> &a, const pair<int, int> &b) {
  return (a.first > b.first);
}
int String_to_int(string s) {
  stringstream geek(s);
  int ans = 0;
  geek >> ans;
  return ans;
}
int S_I(string s) { return stoi(s); }
int main() {
  int n, k;
  cin >> n >> k;
  string s;
  cin >> s;
  set<char> s1;
  sort(s.begin(), s.end());
  string s2 = "";
  map<int, int> m;
  for (int i = 0; i < n; i++) {
    s1.insert(s[i]);
  }
  if (s1.size() <= k) {
    cout << -1 << "\n";
    ;
    return 0;
  }
  for (auto it : s1) {
    s2 += it;
  }
  for (int i = 0; i < s2.size(); i++) {
    int kos = (int)(s2[i]);
    for (int j = i + 1; j < s2.size(); i++) {
      int kos1 = (int)(s2[j]);
      if (abs(kos - kos1) <= 1) {
        s2[j] = '0';
        continue;
      } else {
        break;
      }
    }
  }
  string oii = "";
  for (int i = 0; i < s2.size(); i++) {
    if (s2[i] != '0') {
      oii += s2[i];
    }
  }
  if (oii.size() < k) {
    cout << -1 << "\n";
    ;
    return 0;
  }
  int fin = 0;
  for (int i = 0; i < k; i++) {
    int kos = (int)(oii[i]) - 96;
    fin += kos;
  }
  cout << fin << "\n";
  ;
  return 0;
}
