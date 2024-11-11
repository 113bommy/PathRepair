#include <bits/stdc++.h>
using namespace std;
int arr[1005];
void calc() {
  int n, a, b, c;
  cin >> n;
  a = b = c = 0;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  while (a < n - 2) {
    if (arr[a] < arr[a + 1]) break;
    a++;
  }
  if (a == n - 1) {
    cout << "NO";
    return;
  }
  b = a + 1;
  while (b < n - 1) {
    if (arr[b] > arr[b + 1]) break;
    b++;
  }
  if (b == n - 1) {
    cout << "NO";
    return;
  }
  cout << "YES\n" << (a + 1) << " " << (b + 1) << " " << (b + 2) << endl;
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) calc();
}
