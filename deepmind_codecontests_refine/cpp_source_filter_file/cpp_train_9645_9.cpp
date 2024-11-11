#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  int A[n];
  vector<int> F(700);
  for (int i = 0; i < (int)n; i++) {
    cin >> A[i];
    F[A[i]]++;
  }
  int cnt = 0;
  for (int i = 0; i < (int)700; i++) {
    if (F[i] > 0) {
      cnt++;
    }
  }
  cout << cnt;
}
