#include <bits/stdc++.h>
using namespace std;
long long n, p, a[200005], num[200005], sum[200005], low, up, mid;
bool flag;
vector<int> grafo[200005];
void f(int pos) {
  sum[pos] = a[pos];
  num[pos] = 0;
  for (auto i : grafo[pos]) {
    f(i);
    sum[pos] += sum[i];
    num[pos] += num[i];
  }
  if (grafo[pos].size() == 0) num[pos] = 1;
}
bool g() {
  for (int pos = 1; pos <= n; pos++) {
    if (sum[pos] / num[pos] + int(sum[pos] % num[pos] != 0) > mid) {
      return false;
    }
  }
  return true;
}
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n;
  for (int i = 2; i <= n; i++) {
    cin >> p;
    grafo[p].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    up += a[i];
  }
  f(1);
  low = -1;
  up += 5;
  while (up - low > 1) {
    mid = (up + low) / 2;
    flag = g();
    if (flag) {
      up = mid;
    } else {
      low = mid;
    }
  }
  cout << up << "\n";
  return 0;
}
