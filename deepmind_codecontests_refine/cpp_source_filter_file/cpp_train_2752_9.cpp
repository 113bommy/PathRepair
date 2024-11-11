#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n;
  cin >> n;
  long long arr[n + 2];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int count = 0;
  int count2 = 0;
  for (int i = 0; i < n; i++) {
    if (count == 0 && arr[i] < 0) {
      count2++;
    } else if (arr[i] > 0) {
      count = arr[i];
    } else if (count > 0) {
      count--;
    }
  }
  cout << count2 << endl;
  return 0;
}
