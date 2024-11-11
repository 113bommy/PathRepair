#include <bits/stdc++.h>
using namespace std;
unordered_map<string, vector<string>> m;
unordered_map<string, int> v;
int fa[500001];
int f(string s, int sum) {
  sum++;
  v[s]++;
  int l = 0;
  for (int i = 0; i < m[s].size(); i++) {
    l = 0;
    if (v[m[s][i]] == 0) {
      l = max(f(m[s][i], l), l);
    }
  }
  return sum + l;
}
int fun(string s) {
  int k = 0;
  for (int i = 0; i < m[s].size(); i++) {
    int sum = 1;
    if (v[m[s][i]] == 0) {
      sum = f(m[s][i], sum);
    }
    if (sum > k) k = sum;
  }
  return k;
}
string l(string s) {
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < 97) s[i] = s[i] + 32;
  }
  return s;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  string s;
  cin >> n;
  map<pair<string, string>, int> m1;
  cin.ignore();
  for (int i = 1; i <= n; i++) {
    getline(cin, s);
    string s1, s2;
    size_t p = s.find(' ');
    s1 = s.substr(0, (int)p);
    p = s.find(' ', p + 1);
    s2 = s.substr((int)(p + 1));
    s2 = l(s2);
    s1 = l(s1);
    if (m1[make_pair(s2, s1)] == 0) {
      m[s2].push_back(s1);
      m1[make_pair(s2, s1)]++;
    }
  }
  int t = fun("polycarp");
  cout << t << "\n";
  return 0;
}
