#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ii = pair<ll, ll>;
const int N = 1e4 + 10;
int n, a[N];
struct data {
  int i, j, x;
};
vector<data> soln;
void move(int i, int j, int x) {
  a[i] -= i * x;
  a[j] += i * x;
  soln.push_back({i, j, x});
}
int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    soln.clear();
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++) {
      scanf("%d", &a[i]);
      sum += a[i];
    }
    if (sum % n != 0) {
      puts("-1");
      continue;
    }
    int req = sum / n;
    for (int i = 2; i <= n; i++) {
      if (a[i] % i != 0) move(1, i, i - ((a[i] - req) % i));
      move(i, 1, a[i] / i);
    }
    for (int i = 2; i <= n; i++) move(1, i, req);
    printf("%d\n", (int)soln.size());
    for (auto it : soln) printf("%d %d %d\n", it.i, it.j, it.x);
  }
  return 0;
}
