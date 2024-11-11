#include <bits/stdc++.h>
using namespace std;
int T[1000010];
string s;
void pc(int n) {
  int i = 0;
  int j = -1;
  T[i] = j;
  while (i < n) {
    while (j >= 0 && s[i] != s[j]) j = T[j];
    T[++i] = ++j;
  }
}
bool isp(int sz) {
  int i = 1;
  int j = 0;
  while (i < s.size()) {
    while (j >= 0 && s[i] != s[j]) j = T[j];
    i++;
    j++;
    if (j == sz) return (i != s.size());
  }
  return 0;
}
int main() {
  cin >> s;
  int n = s.size();
  pc(n);
  int anw = -1;
  int mn = 1;
  int mx = n - 2;
  while (mn <= mx) {
    int md = (mn + mx) / 2;
    bool ic = isp(md);
    if (ic) {
      mn = md + 1;
      anw = md;
    } else
      mx = md - 1;
  }
  if (anw == -1)
    cout << "Just a legend" << endl;
  else {
    string h = s.substr(0, anw);
    reverse(h.begin(), h.end());
    reverse(s.begin(), s.end());
    pc(n);
    int i = 1;
    int j = 0;
    while (i < h.size()) {
      while (j >= 0 && h[i] != s[j]) j = T[j];
      i++;
      j++;
    }
    string tp = s.substr(0, j);
    reverse(tp.begin(), tp.end());
    cout << (j == 0 ? "Just a legend" : tp) << endl;
  }
}
