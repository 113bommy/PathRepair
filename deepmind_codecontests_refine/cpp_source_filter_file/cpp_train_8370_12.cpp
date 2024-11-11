#include <bits/stdc++.h>
using namespace std;
int n, m, k, i, j, l, r, sum;
int ans[10000];
vector<int> res;
int tree[100001];
int sum1(int ind) {
  int res = 0;
  while (ind > 1) {
    res += tree[ind];
    ind -= (ind & -ind);
  }
  return res;
}
void update(int ind, int vol) {
  while (ind <= n) {
    tree[ind] += vol;
    ind += (ind & -ind);
  }
}
int main() {
  cin >> n;
  cin >> m;
  ans[0] = 1;
  for (i = 1; i <= 3000; i += 2) {
    if (i % 2) {
      ans[i] = ((i + 1) * (i + 1)) / 2;
    } else {
      ans[i] = 2 * ((i / 2) * (i / 2)) + (i / 2) + 1;
    }
  }
  for (i = 0; i <= 3000; i++) {
    if (ans[i] > n) {
      break;
    }
  }
  k = i;
  for (i = 0; i < m; i++) {
    cin >> l;
    cin >> r;
    res.push_back(r);
  }
  sort(res.begin(), res.end());
  reverse(res.begin(), res.end());
  for (i = 0; i < min(k, m); i++) {
    sum += res[i];
  }
  cout << sum << endl;
}
