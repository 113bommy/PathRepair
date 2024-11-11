#include <bits/stdc++.h>
using namespace std;
int main() {
  int arr[4] = {0, 0, 0, 0};
  int n;
  cin >> n;
  int tots = 0;
  while (n--) {
    int temp;
    cin >> temp;
    arr[temp - 1]++;
  }
  tots += arr[3] + arr[2];
  arr[0] -= arr[2];
  if (arr[0] < 0) arr[0] = 0;
  tots += arr[1] / 2;
  if (arr[1] % 2 != 0) {
    tots += 1;
    arr[0] -= 2;
  }
  if (arr[0] > 0) {
    tots += arr[0] / 4;
    if (arr[0] % 4 != 0) tots++;
  }
  cout << tots << endl;
  return 0;
}
