#include <bits/stdc++.h>
using namespace std;
long long a[100005], tmp[100005], b[100005];
bool die[100005];
int n, m;
vector<long long> candidate;
bool solve(int pos) {
  candidate.clear();
  for (int i = 1; i <= n; i++)
    if ((!die[i]) && (a[i] & (1ll << pos))) {
      candidate.push_back(a[i]);
      die[i] = true;
    }
  for (int i = 1; i <= m; i++) tmp[i] = b[i];
  int len_tmp = m;
  int cur = 1;
  m = 0;
  for (int i = 0; i < candidate.size(); i++) {
    b[++m] = candidate[i];
    while (cur <= len_tmp && !(tmp[cur] & (1 << pos))) {
      b[++m] = tmp[cur];
      cur++;
    }
    if (cur > len_tmp && i != candidate.size() - 1) return false;
    b[++m] = tmp[cur];
    cur++;
  }
  while (cur <= len_tmp) {
    b[++m] = tmp[cur];
    cur++;
  }
  return true;
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 59; i >= 0; i--)
    if (!solve(i)) {
      printf("No");
      return 0;
    }
  cout << "Yes\n";
  for (int i = 1; i <= n; i++) cout << b[i] << ' ';
}
