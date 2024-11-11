#include <bits/stdc++.h>
using namespace std;
struct node {
  int id;
  int x;
  bool operator<(const node &a) const { return x < a.x; }
} qlist[300003];
long long dis[300003];
int main() {
  int n, i;
  scanf("%d", &n);
  for (i = 0; i < n; i++) {
    scanf("%d", &qlist[i].x);
    qlist[i].id = i + 1;
  }
  sort(qlist, qlist + n);
  for (i = 0; i < n - 1; i++) dis[i] = qlist[i + 1].x - qlist[i].x;
  int k, ans;
  long long value = 1e18;
  long long sum = 0, add = 0, qans = 0;
  scanf("%d", &k);
  for (i = n - k; i < n - 1; i++) {
    sum += dis[i];
    qans += 1ll * (i - (n - k) + 1) * (k - (i - (n - k) + 1)) * dis[i];
    add += 2ll * (i - (n - k)) * dis[i];
  }
  value = qans;
  ans = n - k;
  for (i = n - 1 - k; i >= 0; i--) {
    sum -= dis[i + k - 1];
    add -= 2ll * (k - 2) * dis[i + k - 1];
    add += 2ll * sum;
    qans += sum * (k - 1);
    qans -= add;
    sum += dis[i];
    qans -= (k - 1) * dis[i + k - 1];
    qans += (k - 1) * dis[i];
    if (value > qans) {
      value = qans;
      ans = i;
    }
  }
  for (i = ans; i < ans + k; i++) printf("%d ", qlist[i].id);
  return 0;
}
