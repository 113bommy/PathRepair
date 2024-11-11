#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, P, A, B = 0;
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> P;
    A += P;
    B = max(B, P);
  }
  cout << A - B / 2 << endl;
}
