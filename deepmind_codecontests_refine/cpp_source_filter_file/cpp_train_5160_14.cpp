#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  cout << "?"
       << " " << 1 << " " << 2 << endl;
  long long sum1, sum2, sum3;
  cin >> sum1;
  cout << "?"
       << " " << 2 << " " << 3 << endl;
  cin >> sum2;
  cout << "?"
       << " " << 1 << " " << 3 << endl;
  cin >> sum3;
  vector<int> A;
  A.resize(n + 1);
  A[2] = sum1 + sum2 - sum3;
  A[1] = sum1 - A[2];
  A[3] = sum2 - A[2];
  for (int i = 4; i <= n; i++) {
    long long sum;
    cout << "?"
         << " " << i - 1 << " " << i << endl;
    cin >> sum;
    A[i] = sum - A[i - 1];
  }
  cout << "!"
       << " ";
  for (int i = 1; i <= n; i++) {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}
