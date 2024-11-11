#include <bits/stdc++.h>
using namespace std;
int A[19000] = {0};
int main() {
  int a;
  cin >> a;
  A[0] = 1;
  for (int i = 1; i < a; i++) A[i] = A[i - 1] + 6 + 6 * (2 * i - 1);
  cout << A[a - 1] << endl;
}
