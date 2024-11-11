#include <bits/stdc++.h>
using namespace std;
long long coup[300003];
int main() {
  int n;
  cin >> n;
  long long sum = 0;
  int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    sum += arr[i];
  }
  sort(arr, arr + n);
  memset(coup, -1, sizeof(coup));
  int m;
  cin >> m;
  while (m--) {
    int c;
    cin >> c;
    if (coup[c] == -1) {
      coup[c] = sum - arr[n - c];
    }
    cout << coup[c] << endl;
  }
  return 0;
}
