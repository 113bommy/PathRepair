#include <bits/stdc++.h>
using namespace std;
long long n, A, R, M;
vector<long long> v;
long long ans(long long h) {
  long long cntu = 0, cntd = 0;
  for (long long i = 0; i < n; i++) {
    if (v[i] < h) {
      cntu += h - v[i];
    } else {
      cntd += v[i] - h;
    }
  }
  if (M > A + R) {
    return A * cntu + R * cntd;
  } else {
    if (cntu > cntd) {
      return min(A * cntu + R * cntd, M * cntd + A * (cntu - cntd));
    } else {
      return min(A * cntu + R * cntd, M * cntu + R * (cntd - cntu));
    }
  }
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(0);
  cin >> n >> A >> R >> M;
  v.assign(n, 0);
  for (long long i = 0; i < n; i++) {
    cin >> v[i];
  }
  long long hi = 1e9;
  long long lo = 0;
  long long Ans = 0;
  while (hi > lo) {
    long long mid = (hi + lo) >> 1;
    long long ap1 = ans(mid + 1);
    long long am1 = ans(mid - 1);
    long long ac = ans(mid);
    if (ac < am1 && ac < ap1) {
      Ans = ans(mid);
      break;
    }
    if (ap1 > ac)
      hi = mid;
    else
      lo = mid + 1;
  }
  cout << Ans << endl;
  return 0;
}
