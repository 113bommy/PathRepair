#include <bits/stdc++.h>
using namespace std;
const int maxn = 1000010;
int p[maxn];
bool vis[maxn];
int main() {
  int n, k;
  cin >> n >> k;
  for (int i = 1; i <= n; i++) {
    scanf("%d", &p[i]);
  }
  vector<int> cir;
  for (int i = 1; i <= n; i++) {
    if (!vis[i]) {
      int t = i;
      int len = 0;
      while (!vis[t]) {
        vis[t] = 1;
        t = p[t];
        len++;
      }
      cir.push_back(len);
    }
  }
  sort(cir.begin(), cir.end());
  int MAX = 0;
  int kk = k;
  for (int i = 0; i < cir.size(); i++) {
    int tmp = cir[i];
    while (tmp >= 2 && kk > 0) {
      MAX += 2;
      kk--;
      tmp -= 2;
    }
  }
  MAX += kk;
  MAX = min(MAX, n);
  vector<int> vec;
  cir.push_back(-1);
  int s = 0;
  for (int i = 1; i < cir.size(); i++) {
    while (cir[i] == cir[i - 1]) {
      i++;
    }
    int t = i - s;
    s = t;
    int j = 0;
    while (t) {
      int tmp = min(1 << j, t);
      t -= tmp;
      j++;
      vec.push_back(cir[i - 1] * tmp);
    }
    if (cir[i] == -1) {
      break;
    }
  }
  bitset<maxn> bs[2];
  int cur = 0, pre = 1;
  bs[cur][0] = 1;
  for (int i = 0; i < vec.size(); i++) {
    swap(cur, pre);
    bs[cur] = bs[pre] | (bs[pre] << vec[i]);
  }
  int MIN = k + 1 - bs[cur][k];
  cout << MIN << " " << MAX << endl;
  return 0;
}
