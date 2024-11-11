#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long int T;
  cin >> T;
  while (T--) {
    long long int N;
    cin >> N;
    vector<long long int> arr1(N);
    vector<long long int> arr2(N);
    vector<long long int> arr3(N);
    for (auto &it : arr1) cin >> it;
    for (auto &it : arr2) cin >> it;
    for (auto &it : arr3) cin >> it;
    long long int prev = -1;
    for (long long int j = 0; j < N - 1; j++) {
      if (prev != arr1[j]) {
        cout << arr1[j] << " ";
        prev = arr1[j];
      } else if (prev != arr1[j]) {
        cout << arr2[j] << " ";
        prev = arr2[j];
      } else {
        cout << arr3[j] << " ";
        prev = arr3[j];
      }
    }
    if (arr1[N - 1] != arr1[0] and arr1[N - 1] != prev) {
      cout << arr1[N - 1];
    } else if (arr2[N - 1] != arr1[0] and prev != arr2[N - 1]) {
      cout << arr2[N - 1];
    } else {
      cout << arr3[N - 1];
    }
    cout << endl;
  }
}
