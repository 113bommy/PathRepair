#include <bits/stdc++.h>
using namespace std;
int bb[100000];
int prime[20000];
int k, t;
long long now;
vector<pair<int, int> > q;
void search(int x, int y) {
  int i;
  q.push_back(make_pair(now, y));
  for (i = x; (i < t) && (prime[i] < k); i++)
    if (now * prime[i] <= 2000000000) {
      now *= prime[i];
      search(x + 1, y + 1);
      now /= prime[i];
    } else
      break;
}
int main() {
  int i, j, a, b, tmp, left, right;
  long long ans;
  memset(bb, 0, sizeof(bb));
  t = 0;
  for (i = 2; i < 100000; i++)
    if (bb[i] == 0) {
      prime[t] = i;
      t++;
      j = i + i;
      while (j < 100000) {
        bb[j] = 1;
        j += i;
      }
    }
  scanf("%d%d%d", &a, &b, &k);
  for (i = 0; i < t; i++)
    if ((k != prime[i]) && (k % prime[i] == 0)) {
      printf("0\n");
      return 0;
    }
  {
    q.clear();
    now = k;
    search(0, 0);
    ans = 0;
    for (i = 0; i < q.size(); i++) {
      left = (a - 1) / q[i].first;
      right = b / q[i].first;
      if (q[i].second % 2 == 0) {
        ans += right - left;
      } else
        ans -= right - left;
    }
    printf("%d\n", (int)ans);
  }
  return 0;
}
