#include <bits/stdc++.h>
using namespace std;
int A[10010];
int main() {
  int num, col;
  cin >> num >> col;
  int maxn = 0;
  int minn = 10001000;
  for (int i = 0; i < num; i++) {
    cin >> A[i];
    maxn = max(maxn, A[i]);
    minn = min(minn, A[i]);
  }
  if (maxn - minn > col) {
    cout << "NO\n";
    exit(0);
  }
  cout << "YES\n";
  for (int i = 0; i < num; i++) {
    int j = 1;
    for (int k = 0; k < A[i]; k++) {
      cout << j++ << " ";
      if (j > col) {
        j = 1;
      }
    }
    cout << "\n";
  }
}
