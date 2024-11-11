#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int N;
  int K;
  int T;
  cin >> N >> K >> T;
  if (T <= K) {
    cout << T << endl;
  } else if (T > K && T <= N) {
    cout << K << endl;
  } else {
    cout << N + K - T << endl;
  }
}
