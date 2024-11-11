#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> A(n);
  vector<int> G(n);
  for (int i = 0; i < n; i++) {
    cin >> A[i] >> G[i];
  }
  string answer = "";
  long long int sum_A = 0;
  long long int sum_G = 0;
  for (int i = 0; i < n; i++) {
    if (sum_A + A[i] - sum_G < 500) {
      answer += 'A';
      sum_A += A[i];
    } else {
      sum_G += G[i];
      answer += 'G';
    }
  }
  if (abs(sum_G - sum_A) > 500) {
    cout << "-1\n";
    return 0;
  }
  cout << answer << "\n";
  return 0;
}
