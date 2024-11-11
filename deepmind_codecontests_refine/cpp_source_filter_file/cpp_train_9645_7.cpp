#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, x;
  cin >> n;
  int arr[600] = {0};
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr[x]++;
  }
  int count = 0;
  for (int i = 1; i <= 600; i++)
    if (arr[i] > 0) count++;
  cout << count << endl;
  return 0;
}
