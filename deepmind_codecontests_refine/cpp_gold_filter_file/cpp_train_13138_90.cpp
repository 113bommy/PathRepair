#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e6 + 10;
int b[MAXN];
int ada[MAXN];
string p;
string lol = "Just a legend\n";
void kmp() {
  int i = 0, j = -1, n = p.size();
  b[0] = -1;
  while (i < n) {
    while (j >= 0 && p[i] != p[j]) j = b[j];
    i++;
    j++;
    b[i] = j;
    ada[j]++;
  }
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> p;
  kmp();
  if (b[p.size()] == 0)
    cout << lol;
  else if (ada[b[p.size()]] > 1)
    cout << p.substr(0, b[p.size()]);
  else if (b[b[p.size()]] == 0)
    cout << lol;
  else
    cout << p.substr(0, b[b[p.size()]]);
}
