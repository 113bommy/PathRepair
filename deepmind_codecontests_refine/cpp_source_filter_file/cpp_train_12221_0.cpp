#include <bits/stdc++.h>
using namespace std;
const int N = 10000005;
vector<int> vv;
int cnt[N];
int p[N];
int Max;
long long sum;
int n;
void pre() {
  for (int i = 2; i < N; ++i) {
    if (!p[i]) {
      p[i] = i;
      vv.push_back(i);
    }
    for (int j = 0; i * vv[j] < N; ++j) {
      p[i * vv[j]] = vv[j];
      if (i % vv[j] == 0) break;
    }
  }
}
long long cal(long long mid, long long base) {
  long long ret = 0;
  while (mid) {
    ret += (mid /= base);
  }
  return ret;
}
void deal() {
  for (int i = Max; i >= 2; --i) {
    if (p[i] != i) {
      cnt[p[i]] += cnt[i];
      cnt[i / p[i]] += cnt[i];
    }
  }
}
long long get(long long base, long long x) {
  long long l = 1, r = sum;
  long long ret;
  while (l <= r) {
    long long mid = (l + r) >> 1;
    if (cal(mid, base) >= x) {
      ret = mid;
      r = mid - 1;
    } else {
      l = mid + 1;
    }
  }
  return ret;
}
int main() {
  pre();
  scanf("%d", &n);
  int x;
  for (int i = 0; i < n; ++i) {
    scanf("%d", &x);
    sum += x;
    Max = max(Max, x);
    ++cnt[x];
  }
  for (int i = Max - 1; i >= 2; --i) {
    cnt[i] += cnt[i + 1];
  }
  deal();
  long long ret = 1;
  for (int i = 0; i < vv.size(); ++i) {
    ret = max(ret, get(vv[i], cnt[vv[i]]));
  }
  printf("%I64d\n", ret);
  return 0;
}
