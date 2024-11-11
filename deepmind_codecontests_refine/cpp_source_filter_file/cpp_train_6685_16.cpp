#include <bits/stdc++.h>
using namespace std;
const int maxn = 4e5 + 100;
int t;
int n;
vector<int> v;
int getid(int num) {
  return lower_bound(v.begin(), v.end(), num) - v.begin() + 1;
}
struct node {
  int a, b;
} save[maxn];
int in[maxn], out[maxn], sum[maxn], num[maxn];
int maxx = 0;
void init() {
  v.clear();
  for (int i = 1; i <= maxx; i++) {
    in[i] = out[i] = 0;
    sum[i] = 0;
    num[i] = 0;
  }
  maxx = 0;
}
int main() {
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    int x, y;
    for (int i = 1; i <= n; i++) {
      scanf("%d%d", &x, &y);
      x *= 2, y *= 2;
      v.push_back(x);
      v.push_back(y);
      v.push_back(x + 1);
      v.push_back(y + 1);
      v.push_back(x - 1);
      v.push_back(y - 1);
      save[i].a = x;
      save[i].b = y;
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    for (int i = 1; i <= n; i++) {
      save[i].a = getid(save[i].a);
      save[i].b = getid(save[i].b);
    }
    for (int i = 1; i <= n; i++) {
      in[save[i].a]++;
      out[save[i].b]++;
    }
    maxx = v.size();
    int tmp = 0;
    for (int i = 1; i <= maxx; i++) {
      tmp += in[i];
      num[i] += tmp;
      tmp -= out[i];
    }
    for (int i = 1; i <= maxx; i++) {
      if (num[i] == 1 && num[i - 1] != 1)
        sum[i] = sum[i - 1] + 1;
      else
        sum[i] = sum[i - 1];
    }
    int base = 0;
    for (int i = 2; i <= maxx; i++)
      if (num[i - 1] == 0 && num[i]) base++;
    int res = base - 1;
    for (int i = 1; i <= n; i++) {
      x = save[i].a;
      y = save[i].b;
      int add = sum[y] - sum[x - 1];
      if (num[x - 1] == 0 && num[x] == 1) add--;
      if (num[y] == 1 && num[y + 1] == 0) add--;
      res = max(res, base + add);
    }
    printf("%d\n", res);
    init();
  }
  return 0;
}
