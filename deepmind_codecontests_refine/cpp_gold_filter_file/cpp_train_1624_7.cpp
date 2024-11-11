#include <bits/stdc++.h>
using namespace std;
template <typename T>
inline T Abs(T a) {
  return a > 0 ? a : -a;
}
void split(string s, string seps, vector<string> &res, bool doEmpty = false) {
  int start = 0;
  res.clear();
  for (int i = 0; i < s.size(); i++) {
    if (seps.find(s[i]) != string::npos) {
      if (doEmpty || i - start > 0) res.push_back(s.substr(start, i - start));
      start = i + 1;
    }
  }
  if (doEmpty || s.size() - start > 0)
    res.push_back(s.substr(start, s.size() - start));
}
string Union(vector<string> s, int start = 0) {
  string res;
  for (int i = start; i < s.size(); i++) res.append(s[i]);
  return res;
}
int main() {
  string s;
  int n;
  cin >> s >> n;
  vector<string> b(n);
  vector<int> fn(s.size());
  for (int i = 0; i < n; i++) cin >> b[i];
  for (int i = 0; i < n; i++) {
    int k = 0;
    while (k < s.length()) {
      int r = s.find(b[i], k);
      if (r == s.npos) break;
      fn[r + b[i].size() - 1] = max(fn[r + b[i].size() - 1], r + 1);
      k = r + 1;
    }
  }
  int best = 0;
  int bi = 0;
  int cur = 0;
  int ci = 0;
  for (int i = 0; i < s.length(); i++) {
    if (fn[i]) {
      int lci = ci;
      ci = -1;
      int g = fn[i];
      int j = i;
      while (j >= g) {
        g = max(g, fn[j]);
        ci = j;
        j--;
      }
      if (ci == -1) ci = i + 1;
      cur = i - ci;
    }
    cur++;
    if (cur > best) {
      best = cur;
      bi = ci;
    }
  }
  cout << best << ' ' << bi;
  return 0;
}
