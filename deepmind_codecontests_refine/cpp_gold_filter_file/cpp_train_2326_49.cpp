#include <bits/stdc++.h>
using namespace std;
long long D, N, A[2006], Answer;
int main() {
  cin >> D >> N;
  for (int i = 1; i <= N; i++) {
    cin >> A[i];
  }
  for (int i = 1; i < N; i++) {
    Answer += D - A[i];
  }
  cout << Answer << "\n";
  return 0;
}
