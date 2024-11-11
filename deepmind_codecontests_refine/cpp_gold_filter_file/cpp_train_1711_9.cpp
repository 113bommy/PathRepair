#include <bits/stdc++.h>
using namespace std;
const int maxn = 5556555, inf = ~0U >> 1, s = (int)(1e6);
int A[maxn], n, m;
int used[maxn], ok[maxn];
long long sum = 0;
vector<int> val;
vector<pair<long long, long long> > p;
int cnt = 0, ans[maxn];
int main() {
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> A[i];
    sum += A[i] - 1;
    used[A[i]] = 2;
  }
  int k = 1;
  for (int i = 0; i < n; i++) {
    int j = s - A[i] + 1;
    if (used[j] == 3) continue;
    if (j >= 1 && j <= s && !used[j])
      ans[cnt++] = j, used[j] = 1, used[A[i]] = 3;
    else {
      while (k <= s / 2 && !(!used[k] && !used[s - k + 1])) ++k;
      ans[cnt++] = k, ans[cnt++] = s - k + 1;
      used[A[i]] = 3;
      k++;
    }
  }
  cout << cnt << endl;
  for (int i = 0; i < cnt; i++) printf("%d ", ans[i]);
  cout << endl;
}
