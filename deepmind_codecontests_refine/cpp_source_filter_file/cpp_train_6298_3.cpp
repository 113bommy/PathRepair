#include <bits/stdc++.h>
using namespace std;
int main() {
  long long ans[100003], answer = 0;
  int n, m, k, i, a, b, c;
  cin >> n >> m >> k;
  int *l = new int[n + 1];
  int *r = new int[n + 1];
  int *d = new int[n + 1];
  memset(l, 0, (n + 1) * sizeof(int));
  memset(r, 0, (n + 1) * sizeof(int));
  memset(d, 0, (n + 1) * sizeof(int));
  vector<int> v;
  for (i = 0; i < m; i++) {
    cin >> a >> b >> c;
    l[a] += c;
    r[b] += c;
    d[a]++;
    d[b]--;
  }
  for (i = 0; i < k; i++) {
    cin >> a;
    v.push_back(a);
  }
  sort(v.begin(), v.end());
  ans[1] = l[1];
  c = d[1];
  for (i = 2; i <= *(v.end() - 1); i++) {
    ans[i] = ans[i - 1] + l[i] - r[i - 1] + c;
    c += d[i];
  }
  vector<int>::iterator it;
  for (it = v.begin(); it != v.end(); it++) {
    answer += ans[*it];
  }
  cout << answer;
}
