#include <bits/stdc++.h>
using namespace std;
const int maxn = 400000 + 100;
const int MOD = 1000000007;
int n, p, ans;
bool flag;
char cmd[10];
vector<int> vct;
priority_queue<int> buy;
priority_queue<int, vector<int>, greater<int> > sell;
int add(int a, int b) {
  a += b;
  if (a >= MOD) {
    return a - MOD;
  }
  return a;
}
int main() {
  ios::sync_with_stdio(false);
  while (scanf("%d", &n) != EOF) {
    ans = 1;
    flag = true;
    vct.clear();
    while (!buy.empty()) {
      buy.pop();
    }
    while (!sell.empty()) {
      sell.pop();
    }
    buy.push(-1);
    sell.push(INT_MAX);
    for (int i = 0; i < n; ++i) {
      scanf("%s%d", cmd, &p);
      if (!flag) {
        continue;
      }
      if (cmd[1] == 'D') {
        if (p < buy.top()) {
          buy.push(p);
        } else if (p > sell.top()) {
          sell.push(p);
        } else {
          vct.push_back(p);
        }
      } else {
        if (p > sell.top() || p < buy.top()) {
          flag = false;
        } else {
          if (p == sell.top()) {
            sell.pop();
          } else if (p == buy.top()) {
            buy.pop();
          } else {
            ans = add(ans, ans);
          }
          int len = vct.size();
          for (int j = 0; j < len; ++j) {
            if (vct[j] > p) {
              sell.push(vct[j]);
            } else if (vct[j] < p) {
              buy.push(vct[j]);
            }
          }
          vct.clear();
        }
      }
    }
    if (!flag) {
      printf("0\n");
    } else {
      printf("%I64d\n", (long long)ans * ((long long)vct.size() + 1) % MOD);
    }
  }
  return 0;
}
