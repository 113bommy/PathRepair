#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
const int M = 1e6 + 10;
const int zero = 1e3 + 5;
int f[N << 1];
int n, k, a;
pair<int, int> q[3000000];
bool exi[N];
int main() {
  scanf("%d%d", &n, &k);
  for (int i = 1; i <= k; i++) scanf("%d", &a), exi[a] = 1;
  int l = 0, r = 0;
  for (int i = 0; i <= 1000; i++)
    if (exi[i]) q[r++] = make_pair(i - n, 1), f[i - n + zero] = 1;
  while (l < r) {
    pair<int, int> t = q[l++];
    if (t.first == 0) break;
    for (int i = 0; i <= 1000; i++)
      if (exi[i] && (t.first + i - n >= -1000) && (t.first + i - n <= 1000) &&
          (!f[t.first + i - n + zero])) {
        q[r++] = make_pair(t.first + i - n, t.second + 1);
        f[t.first + i - n + zero] = t.second + 1;
      }
  }
  if (f[zero])
    printf("%d\n", f[zero]);
  else
    puts("-1");
  return 0;
}
