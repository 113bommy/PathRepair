#include <bits/stdc++.h>
using namespace std;
int main() {
  int m = 0, c = 0, n, arr[100001], arr1[100001];
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i] >> arr1[i];
    if (arr[i] > arr1[i])
      m++;
    else if (arr[i] < arr1[i])
      c++;
  }
  if (m > c)
    cout << "Mishka";
  else if (m < c)
    cout << "Chris";
  else
    cout << "Friendhsip is magic!^^";
  return 0;
}
