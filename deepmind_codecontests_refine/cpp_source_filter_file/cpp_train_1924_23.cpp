#include <bits/stdc++.h>
using namespace std;
int n, a, b, c, d, k, m, q, z;
map<vector<int>, int> M;
int cnt;
void go(vector<int> V, int r) {
  if (r == k) {
    M[V]++;
    cnt++;
    return;
  }
  r++;
  vector<int> temp = V;
  for (int i = 1; i <= (n); i++) {
    for (int j = i; j <= (n); j++) {
      int a = min(i, j);
      int b = max(i, j);
      temp = V;
      reverse(temp.begin() + a - 1, temp.begin() + b);
      go(temp, r);
    }
  }
}
int iv(vector<int> V) {
  int ret = 0;
  for (int i = 0; i <= (n - 1); i++) {
    for (int j = i; j <= (n - 1); j++) {
      if (V[i] > V[j]) ret++;
    }
  }
  return ret;
}
int main() {
  scanf("%d%d", &n, &k);
  vector<int> V;
  for (int i = 1; i <= (n); i++) {
    scanf("%d", &a);
    V.push_back(a);
  }
  go(V, 0);
  map<vector<int>, int>::iterator it = M.begin();
  long double res = 0;
  for (; it != M.end(); it++) {
    res += iv(it->first) * it->second;
  }
  printf("%.14Lf", res / cnt);
}
