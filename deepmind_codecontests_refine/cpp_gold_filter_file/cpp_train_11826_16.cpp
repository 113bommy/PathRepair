#include <bits/stdc++.h>
using namespace std;
bool myfunction(int i, int j) { return (i > j); }
int main() {
  int n;
  cin >> n;
  int arr[n];
  for (int i = 0; i < n; i++) cin >> arr[i];
  sort(arr, arr + n, myfunction);
  int minn = 2147483647;
  for (int i = 0; i < n - 1; i++) {
    minn = min((arr[i] - arr[i + 1]), minn);
  }
  int c = 0;
  for (int i = 0; i < n - 1; i++) {
    if (arr[i] - arr[i + 1] == minn) {
      c++;
    }
  }
  cout << minn << " " << c << endl;
  return 0;
}
