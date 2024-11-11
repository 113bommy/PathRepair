#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[]) {
  int arr[1001], n, ma = -10001, mai = 0, sol = 0;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> arr[i];
    if (arr[i] > ma) {
      ma = arr[i];
      mai = i;
    }
  }
  while (mai != 0) {
    sol++;
    arr[mai]--;
    arr[0]++;
    ma = -10001;
    mai = -1;
    for (int i = 0; i < n; ++i) {
      if (arr[i] >= ma) {
        ma = arr[i];
        mai = i;
      }
    }
  }
  cout << sol;
  return 0;
}
