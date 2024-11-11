#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:16777216")
using namespace std;
int main() {
  int N, cnt = 0, s = 0, MIN = 2147483647;
  cin >> N;
  vector<int> A(2 * N - 1);
  for (long long i = 0; i < 2 * N - 1; i++) {
    cin >> A[i];
    if (A[i] < 0) cnt++;
  }
  for (long long i = 0; i < 2 * N - 1; i++) s += abs(A[i]);
  for (long long i = 0; i < -1 + 2 * N; i++) MIN = min(MIN, abs(A[i]));
  if (N % 2 == 0) {
    if (cnt % 2 == 0) {
      cout << s;
      return 0;
    } else
      cout << s - 2 * MIN;
    return 0;
  }
  cout << s;
  return 0;
}
