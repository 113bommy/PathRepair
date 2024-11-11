#include <bits/stdc++.h>
using namespace std;
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  ;
  int n;
  cin >> n;
  vector<int> A(n), Ans(5001);
  for (int i = 0; i < n; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < n; i++) {
    vector<int> Temp(5001, 0);
    int val = 0;
    for (int j = i; j < n; j++) {
      Temp[A[j]]++;
      if (Temp[A[j]] > Temp[val]) {
        val = A[j];
        Ans[val]++;
      } else if (Temp[A[j]] == Temp[val]) {
        val = min(val, A[j]);
        Ans[val]++;
      } else {
        Ans[val]++;
      }
    }
  }
  for (int i = 0; i < n; i++) {
    cout << Ans[i] << " ";
  }
  return 0;
}
