#include <bits/stdc++.h>
using namespace std;
const int NN = 1e5 + 10;
int A[NN], B[NN];
int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(0);
  int N, M, k, m;
  cin >> N >> M >> k >> M;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
  }
  int lowest = A[k - 1];
  bool done = false;
  int found = 0;
  for (int i = 0; i < M; i++) {
    if (B[i] > lowest) {
      for (int j = i; j < M; j++) {
        found++;
      }
      done = true;
    }
    if (done) {
      break;
    }
  }
  puts(found >= m ? "YES" : "NO");
  return 0;
}
