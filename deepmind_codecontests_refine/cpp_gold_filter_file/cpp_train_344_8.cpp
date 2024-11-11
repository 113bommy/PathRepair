#include <bits/stdc++.h>
using namespace std;
long long labs(long long a) { return a < 0 ? (-a) : a; }
long long max(long long a, long long b) { return a > b ? a : b; }
long long min(long long a, long long b) { return a < b ? a : b; }
int sor;
int FindFirst(int i, string& s, char c) {
  int from = i;
  for (; i < s.size(); i++) {
    if (s[i] >= c) {
      swap(s[i], s[from]);
      sort(s.begin() + from + 1, s.begin() + sor);
      break;
    }
  }
  return i;
}
int main() {
  string s, t;
  cin >> s >> t;
  sor = s.size();
  sort((s).begin(), (s).end());
  if (t.size() < s.size()) {
    t += string(s.size() - t.size(), ' ');
  }
  if (t.size() > s.size()) {
    s += string(t.size() - s.size(), ' ');
  }
  int from = sor - 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] < t[i]) {
      int ind = FindFirst(i, s, t[i]);
      if (ind == s.size()) {
        from = i;
        break;
      }
    }
    if (s[i] > t[i]) {
      cout << s.substr(0, sor) << endl;
      return 0;
    }
  }
  for (int i = from - 1; i >= 0; i--) {
    sort(s.begin() + i + 1, s.begin() + sor);
    int ind = FindFirst(i, s, t[i] + 1);
    if (ind != s.size()) {
      cout << s.substr(0, sor) << endl;
      return 0;
    }
  }
  cout << "-1\n";
  return 0;
}
