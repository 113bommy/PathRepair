#include <bits/stdc++.h>
using namespace std;
int ptr;
vector<double> M;
vector<double> B;
inline bool bad(int l1, int l2, int l3) {
  return (B[l3] - B[l1]) * (M[l1] - M[l2]) <= (B[l2] - B[l1]) * (M[l1] - M[l3]);
}
inline void add(double m, double b) {
  M.push_back(m), B.push_back(b);
  while ((int)M.size() >= 3 &&
         bad((int)M.size() - 3, (int)M.size() - 2, (int)M.size() - 1)) {
    M.erase(M.end() - 2);
    B.erase(B.end() - 2);
  }
}
inline double query(double x) {
  if (ptr >= (int)M.size()) ptr = (int)M.size() - 1;
  while (ptr < (int)M.size() - 1 &&
         M[ptr + 1] * x + B[ptr + 1] < M[ptr] * x + B[ptr])
    ptr++;
  return M[ptr] * x + B[ptr];
}
double Prev[200100], dp[200100], sum[200100], pre[200100], rev[200100];
int t[200100], n, k;
int main() {
  scanf("%d", &n);
  scanf("%d", &k);
  for (long long i = 1; i < n + 1; i++) {
    scanf("%d", &t[i]);
    sum[i] = sum[i - 1] + t[i];
    rev[i] = rev[i - 1] + 1.0 / t[i];
  }
  for (long long i = 1; i < n + 1; i++) {
    pre[i] = pre[i - 1];
    pre[i] += sum[i] / (double)t[i];
  }
  for (long long i = 1; i < n + 1; i++) Prev[i] = dp[i] = pre[i];
  for (long long j = 2; j < k + 1; j++) {
    M.clear();
    B.clear();
    ptr = 0;
    for (long long i = 1; i < n + 1; i++) {
      add(-sum[i - 1], Prev[i - 1] - pre[i - 1] + rev[i - 1] * sum[i - 1]);
      dp[i] = pre[i] + query(rev[i]);
    }
    for (long long i = 1; i < n + 1; i++) Prev[i] = dp[i];
  }
  printf("%.9lf\n", dp[n]);
  return 0;
}
