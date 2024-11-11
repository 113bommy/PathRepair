#include <bits/stdc++.h>
using namespace std;
template <typename T>
string tostr(const T& t) {
  ostringstream os;
  os << t;
  return os.str();
}
int A[1000005];
int N;
int dp1[1000005];
int dp2[1000005];
int main() {
  cin >> N;
  if (N == 1) {
    cout << "1";
    return 0;
  }
  if (N == 2) {
    cout << "2";
    return 0;
  }
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    cin >> A[i];
  }
  memset(dp1, 0, sizeof dp1);
  memset(dp2, 0, sizeof dp2);
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    if (i == 0 || A[i] <= A[i - 1])
      dp1[i] = 1;
    else {
      dp1[i] = dp1[i - 1] + 1;
    }
  }
  for (int i = (int)(N - 1); i >= (int)(0); --i) {
    if (i == N - 1 || A[i] >= A[i + 1]) {
      dp2[i] = 1;
    } else {
      dp2[i] = dp2[i + 1] + 1;
    }
  }
  int ans = 2;
  for (int i = (int)(0); i <= (int)(N - 1); ++i) {
    ans = max(ans, max(dp1[i], dp2[i]));
    if (i + 1 < N && A[i] < A[i + 1]) {
      ans = max(ans, 1 + dp1[i + 1]);
    }
    if (i - 1 >= 0 && A[i] > A[i - 1]) {
      ans = max(ans, 1 + dp2[i - 1]);
    }
    if (i > 0 && i < N - 1) {
      if (A[i + 1] - A[i - 1] >= 2) {
        ans = max(ans, dp1[i - 1] + dp2[i + 1] + 1);
      }
    }
  }
  ans = min(ans, 1000005);
  cout << ans;
  return 0;
}
