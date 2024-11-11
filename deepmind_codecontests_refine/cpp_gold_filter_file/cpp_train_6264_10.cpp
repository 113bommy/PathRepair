#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 1e6 + 5;
int A[N];
int mx;
int val_max;
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> A[i];
  }
  mx = A[1];
  int pos = 1;
  for (int i = 2; i <= n; i++) {
    if (A[i] > mx) {
      mx = A[i];
      pos = i;
    }
  }
  val_max = pos;
  int val_check1 = 1;
  int val_check2 = n;
  while (val_check1 < val_max && A[val_check1] >= A[val_check1 - 1])
    val_check1++;
  if (val_check1 == val_max) {
    while (val_check2 > val_max && A[val_check2] <= A[val_check2 - 1])
      val_check2--;
    if (val_check2 == val_max)
      cout << "YES";
    else
      cout << "NO";
  } else
    cout << "NO";
  return 0;
}
