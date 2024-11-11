#include <bits/stdc++.h>
using namespace std;
const int SQRT = 316;
const int NMAX = 100000;
int N, M;
vector<long long> a[SQRT + 5];
long long totalS;
long long sumL[NMAX + 5], sumC[NMAX + 5];
int main() {
  cin >> N >> M;
  if (N <= M) {
    for (int i = 1; i <= N; i++) {
      a[i].push_back(0);
      for (int j = 1; j <= M; j++) {
        int x;
        cin >> x;
        a[i].push_back(x);
        totalS += x;
      }
    }
  } else {
    for (int i = 1; i <= M; i++) a[i].push_back(0);
    for (int i = 1; i <= N; i++)
      for (int j = 1; j <= M; j++) {
        int x;
        cin >> x;
        a[j].push_back(x);
        totalS += x;
      }
    swap(N, M);
  }
  if (N <= 4 || M <= 4) {
    cout << totalS << '\n';
    return 0;
  }
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= M; j++) {
      sumL[i] += a[i][j];
      sumC[j] += a[i][j];
    }
  long long sol = 0;
  long long max1 = 0, max2 = 0, max3 = 0, max4 = 0;
  for (int i = 1; i <= N; i++) {
    if (sumL[i] >= max1) {
      max4 = max3;
      max3 = max2;
      max2 = max1;
      max1 = sumL[i];
    } else if (sumL[i] >= max2) {
      max4 = max3;
      max3 = max2;
      max2 = sumL[i];
    } else if (sumL[i] >= max3) {
      max4 = max3;
      max3 = sumL[i];
    } else if (sumL[i] >= max4)
      max4 = sumL[i];
  }
  sol = max(sol, max1 + max2 + max3 + max4);
  long long ans;
  for (int j = 1; j <= M; j++) {
    ans = sumC[j];
    max1 = max2 = max3 = 0;
    for (int i = 1; i <= N; i++) {
      long long f = sumL[i] - a[i][j];
      if (f >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = f;
      } else if (f >= max2) {
        max3 = max2;
        max2 = f;
      } else if (f >= max3)
        max3 = f;
    }
    sol = max(sol, ans + max1 + max2 + max3);
  }
  for (int l1 = 1; l1 < N; l1++)
    for (int l2 = l1 + 1; l2 <= N; l2++) {
      ans = sumL[l1] + sumL[l2];
      max1 = max2 = 0;
      for (int j = 1; j <= M; j++) {
        long long f = sumC[j] - a[l1][j] - a[l2][j];
        if (f >= max1) {
          max2 = max1;
          max1 = f;
        } else if (f >= max2)
          max2 = f;
      }
      sol = max(sol, ans + max1 + max2);
    }
  for (int i = 1; i <= N; i++) {
    ans = sumL[i];
    max1 = max2 = max3 = 0;
    for (int j = 1; j <= M; j++) {
      long long f = sumC[j] - a[i][j];
      if (f >= max1) {
        max3 = max2;
        max2 = max1;
        max1 = f;
      } else if (f >= max2) {
        max3 = max2;
        max2 = f;
      } else if (f >= max3)
        max3 = f;
    }
    sol = max(sol, ans + max1 + max2 + max3);
  }
  max1 = max2 = max3 = max4 = 0;
  for (int i = 1; i <= M; i++) {
    if (sumC[i] >= max1) {
      max4 = max3;
      max3 = max2;
      max2 = max1;
      max1 = sumC[i];
    } else if (sumC[i] >= max2) {
      max4 = max3;
      max3 = max2;
      max2 = sumC[i];
    } else if (sumC[i] >= max3) {
      max4 = max3;
      max3 = sumC[i];
    } else if (sumC[i] >= max4)
      max4 = sumL[i];
  }
  sol = max(sol, max1 + max2 + max3 + max4);
  cout << sol << '\n';
  return 0;
}
