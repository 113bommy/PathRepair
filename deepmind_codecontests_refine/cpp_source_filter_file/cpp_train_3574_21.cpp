#include <bits/stdc++.h>
using namespace std;
using vvll = vector<vector<long long> >;
using vll = vector<long long>;
using vvi = vector<vector<int> >;
using vi = vector<int>;
using vvb = vector<vector<bool> >;
using vb = vector<bool>;
long long mulmod(long long x, long long y) {
  return (x % 1000000007 * y % 1000000007) % 1000000007;
}
long long addmod(long long x, long long y) {
  return (x % 1000000007 + y % 1000000007) % 1000000007;
}
long long power(long long x, long long y) {
  long long res = 1;
  while (y > 0) {
    if (y & 1) res = res * x;
    y = y >> 1;
    x = x * x;
  }
  return res;
}
void testcases(int Case) {
  int N, X;
  cin >> N >> X;
  long long arr[N + 2];
  long long cnt = 0;
  for (int i = 1; i <= N; i++) {
    cin >> arr[i];
  }
  sort(arr + 1, arr + N + 1);
  bool FLAG = false;
  int diff = INT_MAX;
  for (int i = 1; i <= N; i++) {
    if (arr[i] == X) FLAG = true;
  }
  int pos;
  if (FLAG) {
    int minn = INT_MAX;
    for (int i = 1; i <= N; i++) {
      if (arr[i] == X) {
        int DIFF = N - i - (i - 1);
        if (DIFF < minn) {
          minn = DIFF;
          pos = i;
        }
      }
    }
  } else {
    arr[N + 1] = X;
    sort(arr + 1, arr + N + 2);
    for (int i = 1; i <= N + 1; i++) {
      if (arr[i] == X) {
        pos = i;
        break;
      }
    }
    N++;
    cnt++;
  }
  int Left = pos - 1;
  int right = N - pos;
  while (Left != right && (right != (Left + 1))) {
    if (Left < right)
      Left++;
    else if (right < Left)
      right++;
    cnt++;
  }
  cout << cnt << "\n";
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long t;
  t = 1;
  long long Case = 1;
  while (t--) {
    testcases(Case++);
  }
}
