#include <bits/stdc++.h>
using namespace std;
string s, t;
const int N = 2e5 + 5;
void process(int L[], string s, string t) {
  vector<int> ids[26];
  for (int i = 0; i < t.size(); i++) ids[t[i] - 'a'].push_back(i);
  int ptr = 0;
  for (int i = 0; i < s.size(); i++) {
    int cur = s[i] - 'a';
    if (ids[cur].size() == 0) {
      puts("No");
      exit(0);
    }
    if (ptr == t.size())
      L[i] = ids[cur].back() + 1;
    else if (s[i] == t[ptr]) {
      ptr++;
      L[i] = ptr;
    } else {
      int lo = 0, hi = ids[cur].size() - 1;
      while (lo < hi) {
        int md = lo + (hi - lo + 1) / 2;
        if (ids[cur][md] < ptr)
          lo = md;
        else
          hi = md - 1;
      }
      if (ids[cur][lo] >= ptr)
        L[i] = 0;
      else
        L[i] = ids[cur][lo] + 1;
    }
  }
}
int L[N], R[N];
int main() {
  cin >> s >> t;
  process(L, s, t);
  reverse(s.begin(), s.end());
  reverse(t.begin(), t.end());
  process(R, s, t);
  reverse(R, R + (int)s.size());
  for (int i = 0; i < s.size(); i++) {
    if (L[i] + R[i] - 1 < t.size()) return puts("No");
  }
  puts("Yes");
}
