#include <bits/stdc++.h>
using namespace std;
void C() {
  int n;
  cin >> n;
  long long arr[n + 1];
  for (int i = 2; i <= n; i++) {
    cout << "? 1 " << i << endl;
    cin >> arr[i];
  }
  cout << "? 2 3" << endl;
  long long tmp;
  cin >> tmp;
  arr[1] = (arr[2] + arr[3] - tmp) / 2;
  cout << "! " << arr[1];
  for (int i = 2; i < n + 1; i++) {
    cout << " " << arr[i] - arr[1];
  }
  cout << endl;
}
int main() {
  C();
  return EXIT_SUCCESS;
}
