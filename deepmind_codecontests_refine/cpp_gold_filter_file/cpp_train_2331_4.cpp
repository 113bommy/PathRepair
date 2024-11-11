#include <bits/stdc++.h>
using namespace std;
int N, A[202], lesn;
int result;
int main() {
  cin >> N;
  for (int i = 1; i <= 2 * N - 1; ++i) {
    cin >> A[i];
    if (A[i] < 0) ++lesn;
  }
  int minabs = 0x3f3f3f3f;
  for (int i = 1; i <= 2 * N - 1; ++i) {
    result += (A[i] < 0 ? -A[i] : A[i]);
    minabs = min(minabs, (A[i] < 0 ? -A[i] : A[i]));
  }
  if (lesn % 2 == 1 && N % 2 == 0) result -= 2 * minabs;
  cout << result << '\n';
}
