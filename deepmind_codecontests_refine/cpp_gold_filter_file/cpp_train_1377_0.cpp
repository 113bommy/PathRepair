#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const* argv[]) {
  int t;
  cin >> t;
  while (t--) {
    char A[102], B[102], C[102];
    cin >> A;
    cin >> B;
    cin >> C;
    int n = strlen(A);
    int count = 0;
    for (int i = 0; i < n; i += 1) {
      if (C[i] == A[i] || C[i] == B[i]) {
        count++;
      }
    }
    if (count == n) {
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }
  return 0;
}
