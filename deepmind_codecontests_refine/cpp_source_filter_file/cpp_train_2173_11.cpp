#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, L;
  cin >> N >> L;
  string S[101];
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  sort(S, S + N);
  for (int i = 0; i < L; i++) {
    cout << S[i];
  }
}
