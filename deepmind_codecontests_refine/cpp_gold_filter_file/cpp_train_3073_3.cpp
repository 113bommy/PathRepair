#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> brks;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
int calc(vector<int> bead, bool sure);
int split(vector<int> bead, int div, bool sure) {
  for (int i = (0); i <= (n - 1); i++) bead[i] /= div;
  return div * calc(bead, sure);
}
int calc(vector<int> bead, bool sure) {
  int G = bead[0];
  for (int i = 1; i <= (n - 1); i++) G = gcd(G, bead[i]);
  if (G == 1) {
    int cnt = 0;
    for (int i = 0; i < n; i++)
      if (bead[i] % 2 == 1) cnt++;
    return cnt == 1;
  }
  if (G == 2) {
    if (sure) brks.push_back(2);
    return 2;
  } else {
    int ret = split(bead, G, false), brk = G;
    for (int j = 2; j * j <= G; j++)
      if (G % j == 0) {
        int tmp = split(bead, j, false);
        if (tmp >= ret) ret = tmp, brk = j;
        tmp = split(bead, G / j, false);
        if (tmp >= ret) ret = tmp, brk = G / j;
      }
    if (sure) {
      split(bead, brk, true);
      brks.push_back(brk);
    }
    return ret;
  }
}
vector<int> necklace(vector<int> bead, int cur) {
  vector<int> ret;
  if (cur < 0 || brks[cur] == 2) {
    for (int i = 0; i < n; i++)
      for (int j = 1; j <= (bead[i] / 2); j++) ret.push_back(i);
    for (int i = 0; i < n; i++)
      if (bead[i] % 2 == 1) ret.push_back(i);
    for (int i = n - 1; i >= 0; i--)
      for (int j = 1; j <= (bead[i] / 2); j++) ret.push_back(i);
    return ret;
  } else {
    for (int i = (0); i <= (n - 1); i++) bead[i] /= brks[cur];
    ret = necklace(bead, cur - 1);
    int len = ret.size();
    for (int i = 1; i <= (brks[cur] - 1); i++)
      for (int j = 0; j < len; j++) ret.push_back(ret[j]);
    return ret;
  }
}
int main() {
  scanf("%d", &n);
  vector<int> bead;
  for (int i = 1; i <= (n); i++) {
    int a;
    cin >> a;
    bead.push_back(a);
  }
  printf("%d\n", calc(bead, true));
  vector<int> sol = necklace(bead, brks.size() - 1);
  for (int i = 0; i < sol.size(); i++) printf("%c", 'a' + sol[i]);
  printf("\n");
  return 0;
}
