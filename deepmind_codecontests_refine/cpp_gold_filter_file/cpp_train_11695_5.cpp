#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int input;
  cin >> input;
  int arr[101][101] = {0};
  for (int i = 0; i < input; i++) {
    for (int j = 0; j < input; j++) {
      cin >> arr[i][j];
    }
  }
  int cnt = (input / 2);
  long long sum = 0;
  for (int i = 0; i < cnt; i++) {
    for (int j = i; j < input - i; j += (cnt - i)) {
      sum += arr[i][j];
      sum += arr[input - i - 1][j];
    }
  }
  for (int i = 0; i < input; i++) {
    sum += arr[input / 2][i];
  }
  cout << sum;
}
