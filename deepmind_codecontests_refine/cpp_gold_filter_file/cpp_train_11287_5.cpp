#include <bits/stdc++.h>
using namespace std;
const long long int infL = 1e18;
const int inf = 1e9 + 7;
const int maxn = 100004;
int main() {
  int n;
  cin >> n;
  ;
  int arr[maxn];
  int diff[maxn];
  for (int(i) = 0; (i) < (n); ++(i)) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  bool all_same = true;
  for (int(i) = 1; (i) < (n); ++(i)) {
    if (arr[i] == arr[0]) {
      continue;
    } else {
      all_same = false;
      break;
    }
  }
  if (n == 1) {
    cout << -1 << endl;
    return 0;
  } else if (all_same) {
    cout << 1 << endl;
    cout << arr[0] << endl;
    return 0;
  } else if (n == 2) {
    if ((arr[0] + arr[1]) / 2 * 2 == (arr[0] + arr[1])) {
      cout << 3 << endl;
      cout << arr[0] - (arr[1] - arr[0]) << " " << (arr[0] + arr[1]) / 2 << " "
           << arr[1] + (arr[1] - arr[0]) << endl;
      return 0;
    }
  }
  int differe = inf;
  for (int(i) = 1; (i) < (n); ++(i)) {
    diff[i - 1] = arr[i] - arr[i - 1];
    if (differe > diff[i - 1]) {
      differe = diff[i - 1];
    }
  }
  for (int(i) = 0; (i) < (n - 1); ++(i)) {
    diff[i] -= differe;
  }
  int diff_cnt = 0;
  for (int(i) = 0; (i) < (n - 1); ++(i)) {
    if (diff[i] == differe) {
      diff_cnt++;
    } else if (diff[i] != differe && diff[i] != 0) {
      diff_cnt = 2;
    }
  }
  if (diff_cnt > 1) {
    cout << 0 << endl;
    return 0;
  } else if (diff_cnt == 0) {
    cout << 2 << endl;
    cout << arr[0] - differe << " " << arr[n - 1] + differe << endl;
  } else {
    cout << 1 << endl;
    for (int(i) = 0; (i) < (n - 1); ++(i)) {
      if (arr[i] + differe != arr[i + 1]) {
        cout << arr[i] + differe << endl;
        break;
      }
    }
  }
  return 0;
}
