#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  bool Yes = 1;
  int Main[1001] = {0};
  cin >> N;
  int arr[N];
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    Main[arr[i]] += 1;
  }
  if (N == 1) {
    cout << "YES";
  } else if (N == 2) {
    if (arr[0] == arr[1])
      cout << "NO";
    else
      cout << "YES";
  } else if (N == 3) {
    if (arr[0] == arr[1] && arr[1] == arr[2])
      cout << "NO";
    else
      cout << "YES";
  } else {
    if (N % 2 == 0) {
      for (int i = 0; i < 1001; i++) {
        if (Main[i] > (N / 2)) Yes = 0;
      }
    } else if (N % 2 != 0) {
      for (int i = 0; i < 1001; i++) {
        if (Main[i] > (N / 2) + 2) Yes = 0;
      }
    }
    if (Yes == 1)
      cout << "YES";
    else
      cout << "NO";
  }
  return 0;
}
