#include <bits/stdc++.h>
using namespace std;
int n;
char A[200];
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> A[i];
  for (int i = 1; i <= n; i++) {
    for (int j = 1; 4 * j <= n; j++) {
      if (A[i] == '*')
        if (A[i] == A[i + j])
          if (A[i + j] == A[i + 2 * j])
            if (A[i + 2 * j] == A[i + 3 * j])
              if (A[i + 3 * j] == A[i + 4 * j]) {
                cout << "yes";
                return 0;
              }
    }
  }
  cout << "no";
  return 0;
}
