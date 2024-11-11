#include <bits/stdc++.h>
using namespace std;
long long A[60] = {0, 2, 4, 8};
int main() {
  for (int i = 4; i <= 55; i++) A[i] = 2 * A[i - 1];
  for (int i = 1; i <= 55; i++) A[i] += A[i - 1];
  int n;
  cin >> n;
  cout << A[n] << endl;
  return 0;
}
