#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int N;
  cin >> N;
  vector<int> arr(N);
  bool flagOdd = false, flagEven = true;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    if (arr[i] % 2) {
      flagOdd = true;
    } else {
      flagEven = true;
    }
  }
  if (flagOdd && flagEven) {
    sort(arr.begin(), arr.end());
  }
  for (int i = 0; i < N; i++) {
    cout << arr[i] << " ";
  }
}
