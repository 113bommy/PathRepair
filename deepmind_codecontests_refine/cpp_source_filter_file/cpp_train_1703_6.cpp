#include <bits/stdc++.h>
using namespace std;
char A[500001];
string alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
map<char, int> m;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  for (int i = 0; i < 26; ++i) {
    m[alphabet[i]] = i;
  }
  int n;
  int k;
  set<char> s;
  cin >> n >> k;
  for (int i = 0; i < n; ++i) {
    cin >> A[i];
  }
  if (k == 2) {
    if (n == 1) {
      cout << "0"
           << "\n";
      cout << A[0];
    } else if (n == 2) {
      if (A[0] == A[1]) {
        A[0] = alphabet[1 - m[A[0]]];
        cout << "1"
             << "\n";
        cout << A[0] << A[1];
      } else {
        cout << "0"
             << "\n";
        cout << A[0] << A[1];
      }
    } else {
      int ans_1 = 0;
      int ans_2 = 0;
      for (int i = 0; i < n; ++i) {
        if (i % 2 == 0) {
          if (A[i] != 'A')
            ++ans_1;
          else
            ++ans_2;
        } else {
          if (A[i] != 'B')
            ++ans_1;
          else
            ++ans_2;
        }
      }
      if (ans_1 <= ans_2) {
        cout << ans_1 << "\n";
        for (int i = 0; i < n; ++i) {
          if (i % 2 == 0)
            cout << "A";
          else
            cout << "B";
        }
      } else {
        cout << ans_2 << "\n";
        for (int i = 0; i < n; ++i) {
          if (i % 2 == 0)
            cout << "B";
          else
            cout << "A";
        }
      }
    }
  } else {
    int ans = 0;
    int kk = n - 1;
    for (int i = 1; i < n; i += 2) {
      if (A[i] == A[i - 1]) {
        ans++;
        if (i == kk) {
          if (m[A[i]] == 0)
            A[i] = alphabet[1];
          else
            A[i] = alphabet[0];
        } else {
          char aa = A[i + 1];
          int alpha = m[A[i]];
          int beta = m[aa];
          int res = max(beta, alpha);
          int mini = min(beta, alpha);
          if (res == k - 1) {
            if (mini != k - 2)
              A[i] = alphabet[k - 2];
            else
              A[i] = alphabet[mini - 1];
          } else
            A[i] = alphabet[k - 1];
        }
      }
    }
    cout << ans << "\n";
    for (int i = 0; i < n; ++i) cout << A[i];
  }
  return 0;
}
