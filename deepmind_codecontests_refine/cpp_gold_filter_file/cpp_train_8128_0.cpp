#include <bits/stdc++.h>
using namespace std;
const int N = 4e5 + 1;
int a[51][51];
struct mahakal {
  int val;
  char c;
};
bool cnt(mahakal x, mahakal y) { return x.val < y.val; }
int main() {
  string s;
  cin >> s;
  int k;
  cin >> k;
  int n = s.size();
  mahakal h[26];
  for (int i = 0; i < 26; i++) h[i].val = 0, h[i].c = ' ';
  for (int i = 0; i < n; i++) h[s[i] - 'a'].c = s[i], h[s[i] - 'a'].val++;
  sort(h, h + 26, cnt);
  int i = 0;
  while (i < 26 && k >= h[i].val) {
    k -= h[i].val;
    h[i].val = 0;
    i++;
  }
  int ans = 0;
  for (int i = 0; i < 26; i++) {
    if (h[i].val > 0) ans++;
  }
  cout << ans << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 26; j++) {
      if (h[j].c == s[i] && h[j].val > 0) cout << s[i];
    }
  }
}
