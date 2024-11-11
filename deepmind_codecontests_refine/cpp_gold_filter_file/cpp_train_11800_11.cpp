#include <bits/stdc++.h>
using namespace std;
vector<string> in;
const int maxn = 2005;
const int INF = 1000000000;
int h[maxn];
int init(string a, string b) {
  int ret = 0;
  for (int i = 0; i < a.size() && i < b.size(); i++) {
    if (a[i] == b[i])
      ret++;
    else
      break;
  }
  return ret;
}
void init(int n) {
  string str;
  int i;
  in.clear();
  for (i = 0; i < n; i++) {
    cin >> str;
    in.push_back(str);
  }
  sort(in.begin(), in.end());
  for (i = 0; i < n - 1; i++) {
    h[i] = init(in[i], in[i + 1]);
  }
}
vector<int> gao(int l, int r) {
  vector<int> ret;
  int i, j;
  ret.resize(r - l + 2);
  for (i = 0; i < r - l + 2; i++) ret[i] = 0;
  if (l == r) return ret;
  vector<int> a, b;
  int mid = l;
  for (i = l; i < r; i++)
    if (h[i] < h[mid]) mid = i;
  a = gao(l, mid);
  b = gao(mid + 1, r);
  int la = mid - l + 1;
  int lb = r - (mid + 1) + 1;
  for (i = 0; i <= la; i++)
    for (j = 0; j <= lb; j++) {
      if (a[i] + b[j] + i * j * h[mid] > ret[i + j])
        ret[i + j] = a[i] + b[j] + i * j * h[mid];
    }
  return ret;
}
int main() {
  int n, k;
  int i, j;
  while (scanf("%d%d", &n, &k) != -1) {
    init(n);
    vector<int> ans = gao(0, n - 1);
    printf("%d\n", ans[k]);
  }
}
