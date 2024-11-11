#include <bits/stdc++.h>
const double eps = (1e-10);
using namespace std;
int dcmp(long double a, long double b) {
  return fabsl(a - b) <= eps ? 0 : (a > b) ? 1 : -1;
}
long long getBit(int num, int idx) { return ((num >> idx) & 1) == 1; }
long long setBit1(int num, int idx) { return num | (1 << idx); }
long long setBit0(long long num, int idx) { return num & ~(1ll << idx); }
long long flipBit(long long num, int idx) { return num ^ (1ll << idx); }
void M() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
}
int countNumBit1(int mask) {
  int ret = 0;
  while (mask) {
    mask &= (mask - 1);
    ++ret;
  }
  return ret;
}
string s, t;
int mem[1009][1009];
int inf = INT_MAX / 10;
vector<vector<int> > v(28);
int solve(int i, int j) {
  int &ret = mem[i][j];
  if (ret != -1) return ret;
  if (j == ((int)(t).size())) {
    return ((int)(s).size()) - i;
  }
  if (i == ((int)(s).size())) return ((int)(t).size()) - j;
  int fl, p1 = inf, p2 = inf, p3 = inf, p4 = inf, id;
  if (s[i] == t[j]) p1 = solve(i + 1, j + 1);
  p2 = 1 + solve(i + 1, j + 1);
  p3 = 1 + solve(i, j + 1);
  p4 = 1 + solve(i + 1, j);
  return ret = min(p1, min(p2, min(p3, p4)));
}
void print(int i, int j, int ex) {
  if (j == ((int)(t).size())) {
    for (int l = i; l < ((int)(s).size()); l++)
      cout << "DELETE " << i + ex + 1 << endl;
    return;
  }
  if (i == ((int)(s).size())) {
    for (int k = j; k < ((int)(t).size()); k++)
      cout << "INSERT " << i + ex + 1 << " " << t[k] << endl, ex++;
    return;
  }
  int fl, p1 = inf, p2 = inf, p3 = inf, p4 = inf, id;
  if (s[i] == t[j]) p1 = solve(i + 1, j + 1);
  p2 = 1 + solve(i + 1, j + 1);
  p3 = 1 + solve(i, j + 1);
  if (!fl) p4 = 1 + solve(i + 1, j);
  if (p2 <= p1 && p2 <= p3 && p2 <= p4) {
    cout << "REPLACE " << i + ex + 1 << " " << t[j] << endl;
    return print(i + 1, j + 1, ex);
  } else if (p3 <= p1 && p3 <= p2 && p3 <= p4) {
    cout << "INSERT " << i + ex + 1 << " " << t[j] << endl;
    return print(i, j + 1, ex + 1);
  } else if (p4 <= p1 && p4 <= p2 && p4 <= p3) {
    cout << "DELETE " << i + ex + 1 << endl;
    return print(i + 1, j, ex - 1);
  } else if (p1 <= p2 && p1 <= p3 && p1 <= p4)
    return print(i + 1, j + 1, ex);
}
int main() {
  cin >> s >> t;
  for (int i = 0; i < ((int)(s).size()); i++) {
    int no = s[i] - 'A';
    v[no].push_back(i);
  }
  memset(mem, -1, sizeof(mem));
  cout << solve(0, 0) << endl;
  print(0, 0, 0);
}
