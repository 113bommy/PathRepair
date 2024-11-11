#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n, m, k;
  cin >> n >> m >> k;
  int b[n];
  for (int i = 0; i < n; i++) cin >> b[i];
  if (k >= n) {
    cout << n << endl;
    return 0;
  }
  int tape[n - 1];
  long long int tcost = b[n - 1] - b[0] + 1;
  for (int i = 0; i < n - 1; i++) tape[i] = b[i + 1] - b[i] - 1;
  sort(tape, tape + n - 1);
  reverse(tape, tape + n - 1);
  for (int i = 0; i < min(k - 1, n - 2); i++) tcost -= (long long int)tape[i];
  cout << tcost << endl;
}
