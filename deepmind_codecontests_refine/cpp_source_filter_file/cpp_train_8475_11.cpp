#include <bits/stdc++.h>
using namespace std;
bool arr[105][105];
int main() {
  int N;
  char C;
  cin >> N;
  for (long long int i = (0); i < (long long int)(N); ++i) {
    for (long long int j = (0); j < (long long int)(N); ++j) {
      cin >> C;
      arr[i][j] = (C == '#');
    }
  }
  for (int i = 1; i < N - 1; i++) {
    for (int j = 1; j < N - 1; j++) {
      if (arr[i][j] && arr[i - 1][j] && arr[i][j - 1] && arr[i + 1][j] &&
          arr[i][j + 1]) {
        arr[i][j] = arr[i - 1][j] = arr[i][j - 1] = arr[i + 1][j] =
            arr[i][j + 1] = 0;
      }
    }
  }
  for (long long int i = (0); i < (long long int)(N); ++i) {
    for (long long int j = (0); j < (long long int)(N - 1); ++j) {
      if (arr[i][j]) {
        cout << "NO" << endl;
        return 0;
      }
    }
  }
  cout << "YES" << endl;
  return 0;
}
