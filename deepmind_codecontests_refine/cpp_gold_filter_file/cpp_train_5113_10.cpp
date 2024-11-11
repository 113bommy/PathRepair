#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 50;
int n, s;
int fir[maxn], sec[maxn];
bool judge() {
  if (fir[1] == 1 && fir[s] == 1) return true;
  bool flag = false;
  for (int i = s + 1; i <= n; i++)
    if (fir[i] == 1 && sec[i] == 1) {
      flag = true;
      break;
    }
  if (fir[1] == 1 && sec[s] == 1 && flag) return true;
  return false;
}
int main() {
  scanf("%d %d", &n, &s);
  for (int i = 1; i <= n; i++) scanf("%d", &fir[i]);
  for (int i = 1; i <= n; i++) scanf("%d", &sec[i]);
  if (judge())
    puts("YES");
  else
    puts("NO");
  return 0;
}
