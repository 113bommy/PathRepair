#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9 + 10;
const long long int LINF = 1LL * INF * INF;
const int MAXN = 1e5 + 10;
const int MAXM = 3e3 + 10;
priority_queue<int> pq;
vector<vector<int> > graph;
int A[5];
int ct[5];
char S[MAXN];
char S1[MAXN];
int main() {
  int n, m, k, a, b, c, d, x, y;
  int sum = 0;
  int cnt = 0;
  scanf("%d", &n);
  scanf("%s", &S);
  scanf("%s", &S1);
  for (int i = 0; i < n; i++) {
    S[i] -= '0';
    S1[i] -= '0';
  }
  for (int i = 0; i < n; i++) {
    A[S[i] * 2 + S1[i]]++;
  }
  int cur;
  vector<int> res;
  for (int i = 0; i <= n / 2; i++) {
    for (int j = 0; j <= i; j++) {
      if (j <= A[2] && i - j <= A[3]) {
        if (2 * i - j - A[3] <= A[1] && 2 * i - j - A[3] >= 0) {
          a = j;
          b = i - j;
          c = A[1] + A[3] + j - 2 * i;
          d = n / 2 - (a + b + c);
          if (d < 0 && d > A[0]) continue;
          for (int i = 0; i < n; i++) {
            cur = S[i] * 2 + S1[i];
            if (cur == 0 && ct[cur] < d) ct[cur]++, res.push_back(i + 1);
            if (cur == 1 && ct[cur] < c) ct[cur]++, res.push_back(i + 1);
            if (cur == 2 && ct[cur] < a) ct[cur]++, res.push_back(i + 1);
            if (cur == 3 && ct[cur] < b) ct[cur]++, res.push_back(i + 1);
          }
          for (int i = 0; i < res.size(); i++) printf("%d ", res[i]);
          return 0;
        }
      }
    }
  }
  printf("-1");
  return 0;
}
