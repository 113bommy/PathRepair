#include <bits/stdc++.h>
using namespace std;
int SetBit(int n, int X) { return n | (1 << X); }
int ClearBit(int n, int X) { return n & ~(1 << X); }
int ToggleBit(int n, int X) { return n ^ (1 << X); }
bool CheckBit(int n, int X) { return (bool)(n & (1 << X)); }
const int MAX = 1e8;
int main() {
  int t;
  scanf("%d", &t);
  for (int z = 1; z <= t; z++) {
    string h, p;
    int f = 0;
    cin >> p >> h;
    sort(p.begin(), p.end());
    int n = p.size();
    if (p.size() > h.size()) {
      printf("NO\n");
      continue;
    }
    for (int i = 0; i < h.size(); i++) {
      string s = h.substr(i, n);
      sort(s.begin(), s.end());
      if (p == s) f = 1;
    }
    f ? printf("YES\n") : printf("NO\n");
  }
  return 0;
}
