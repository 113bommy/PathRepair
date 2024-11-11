#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n, a, b, c, d = 0;
  cin >> n;
  long long int count = 0;
  long long int arr[n];
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
    c = arr[i];
    if (a == 1 && b == 0 && c == 1) {
      c = 0;
      d++;
    }
    a = b;
    b = c;
  }
  if (n == 3 && arr[0] == 1 && arr[1] == 0 && arr[2] == 1) {
    cout << 1;
    return 0;
  }
  count = d;
  cout << count;
}
