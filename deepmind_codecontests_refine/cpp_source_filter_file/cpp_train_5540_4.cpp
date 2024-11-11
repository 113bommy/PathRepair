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
  int anw = *max_element(T + 1, T + n - 1);
  string h = s.substr(0, anw);
  reverse(h.begin(), h.end());
  reverse(s.begin(), s.end());
  pc(n);
  int i = 0;
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
