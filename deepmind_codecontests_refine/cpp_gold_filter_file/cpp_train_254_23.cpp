#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 1e9 + 1e5 + 10;
int n, k, a[N];
char buffer[256];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; i++) {
    scanf("%s", buffer);
    if (buffer[0] == '?')
      a[i] = M;
    else
      a[i] = atoi(buffer);
  }
  for (int i = 0; i < k; i++) {
    int last_id, low, hi, now;
    now = i;
    low = -M;
    while (now < n) {
      if (a[now] == M) {
        last_id = now;
        for (; now < n && a[now] == M; now += k)
          ;
        if (now >= n)
          hi = M;
        else
          hi = a[now];
        int r = (now - last_id) / k;
        if ((hi - low) <= r) {
          puts("Incorrect sequence");
          return 0;
        }
        low = max(low, min(-(r + 2) / 2, hi - r - 1));
        for (; last_id < now; last_id += k) {
          low++;
          a[last_id] = low;
        }
      }
      if (now < n) {
        if (a[now] <= low) {
          puts("Incorrect sequence");
          return 0;
        }
        low = a[now];
      }
      now += k;
    }
  }
  for (int i = 0; i < n; i++) printf("%d ", a[i]);
  return 0;
}
