#include <bits/stdc++.h>
using namespace std;
int main() {
  string A;
  int i;
  cin >> A;
  i = A.size();
  int upp = 0, low = 0;
  for (int j = 0; j < i; j++) {
    if (A[j] >= 'A' && A[j] <= 'Z') upp++;
    if (A[j] >= 'a' && A[j] <= 'z') low++;
  }
  if (low <= upp)
    transform(A.begin(), A.end(), A.begin(), ::toupper);
  else
    transform(A.begin(), A.end(), A.begin(), ::tolower);
  cout << A;
}
