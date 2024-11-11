#include <bits/stdc++.h>
const int maxn = 1000050;
const int maxm = 300050;
using namespace std;
int ct[maxn];
int num[400050];
int n;
int main() {
  int T;
  cin >> T;
  while (T--) {
    scanf("%d", &n);
    vector<int> x;
    int i, j;
    for (i = 1; i <= n; i++) {
      int tmp;
      scanf("%d", &tmp);
      if (ct[tmp] == 0) x.push_back(tmp);
      ct[tmp]++;
    }
    num[0] = ct[x[0]];
    int rec = -1, s = -1;
    for (i = 1; i < x.size(); i++) {
      num[i] = num[i - 1] + ct[x[i]];
      if (num[i] >= n / 2) {
        rec = i;
        break;
      }
      if (num[i] - num[0] > num[0] && s == -1) s = i;
    }
    if (rec < 3 || s == -1 || num[rec - 1] - num[s] < num[0]) {
      printf("0 0 0\n");
      for (i = 0; i < x.size(); i++) {
        num[i] = 0;
        ct[x[i]] = 0;
      }
      continue;
    }
    printf("%d %d %d\n", num[0], num[s] - num[0], num[rec - 1] - num[s]);
    for (i = 0; i < x.size(); i++) {
      num[i] = 0;
      ct[x[i]] = 0;
    }
  }
}
