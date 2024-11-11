#include <bits/stdc++.h>
using namespace std;
const int INF = int(pow(2, 31) - 1);
int n;
string S;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  cin >> n;
  cin >> S;
  bool taken = false;
  int i;
  for (i = 0; i < n - 1; i++) {
    if (not taken and S[i] > S[i + 1]) {
      taken = true;
      continue;
    }
    cout << S[i];
  }
  if (taken) cout << S[n - 1];
  cout << '\n';
}
