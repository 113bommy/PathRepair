#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
int n;
int A[MAXN];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  if (A[n] == 1) {
    cout << "NO";
  } else {
    if (n == 1) {
      cout << "YES\n";
      cout << 0;
    } else {
      if (A[n - 1] == 1) {
        cout << "YES\n";
        for (int i = 1; i <= n - 1; i++) {
          cout << A[i] << "->";
        }
        cout << A[n];
      } else {
        if (n == 2) {
          cout << "NO\n";
        } else {
          int id = -1;
          for (int i = n - 2; i >= 1; i--) {
            if (A[i] == 0) {
              id = i;
              break;
            }
          }
          if (id == -1) {
            cout << "NO\n";
          } else {
            cout << "YES\n";
            for (int i = 1; i < id; i++) {
              cout << A[i] << "->";
            }
            cout << "(0->(";
            for (int i = id + 1; i < n - 1; i++) {
              cout << "1->";
            }
            cout << "0))->0";
          }
        }
      }
    }
  }
}
