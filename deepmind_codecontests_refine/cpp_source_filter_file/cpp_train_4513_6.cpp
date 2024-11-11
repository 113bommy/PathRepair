#include <bits/stdc++.h>
using namespace std;
const int MAX = 200005;
int N;
int mapp[MAX], A[MAX], B[MAX];
int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    A[i]--;
  }
  for (int i = 0; i < N; i++) {
    cin >> B[i];
    B[i]--;
    mapp[B[i]] = i;
  }
  for (int i = 0; i < N; i++) {
    A[i] = mapp[A[i]];
  }
  int res = 0;
  for (int i = 0; i < N; i++) {
    if (i == 0) continue;
    if (A[i - 1] > A[i]) {
      res = i - 1;
      break;
    }
  }
  cout << N - 1 - res << endl;
}
