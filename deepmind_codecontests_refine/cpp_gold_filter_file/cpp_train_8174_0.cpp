#include <bits/stdc++.h>
using namespace std;
int n;
int a[100010];
int b[100010];
int ok[100010];
int ok2[100010];
long long int cnt;
long long int minn1 = 1000000001, minn2 = 1000000001;
vector<int> rr;
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++) scanf("%d", &b[i]);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  cnt = b[0];
  for (int i = 0; i < n; i++) {
    cnt -= a[i];
    minn1 = ((minn1) < (cnt) ? (minn1) : (cnt));
    cnt += b[(i + 1) % n];
  }
  cnt = b[0];
  for (int i = 0; i < n; i++) {
    cnt -= a[i];
    if (cnt == minn1) {
      ok[(i + 1) % n] = 1;
    }
    cnt += b[(i + 1) % n];
  }
  cnt = b[0];
  for (int i = n - 1; i >= 0; i--) {
    cnt -= a[i];
    minn2 = ((minn2) < (cnt) ? (minn2) : (cnt));
    cnt += b[i];
  }
  cnt = b[0];
  for (int i = n - 1; i >= 0; i--) {
    cnt -= a[i];
    if (cnt == minn2) {
      ok2[i] = 1;
    }
    cnt += b[i];
  }
  int res = 0;
  for (int i = 0; i < n; i++)
    if (ok[i] || ok2[i]) res++;
  printf("%d\n", res);
  for (int i = 0; i < n; i++) {
    if (ok[i] && i <= n - 1)
      rr.push_back(i + 1);
    else if (ok2[i])
      rr.push_back(i + 1);
  }
  sort(rr.begin(), rr.end());
  for (int i = 0; i < rr.size(); i++) printf("%d ", rr[i]);
  printf("\n");
  return 0;
}
