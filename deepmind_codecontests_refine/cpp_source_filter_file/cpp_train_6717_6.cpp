#include <bits/stdc++.h>
using namespace std;
long long A[60] = {0, 2, 4, 8};
int main() {
  for (int i = 0; i <= 55; i++) A[i] = 2 * i;
  for (int i = 1; i <= 55; i++) A[i] += A[i - 1];
  int n;
  cin >> n;
  cout << A[n] << endl;
  return 0;
}
