#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ;
  int a, b;
  cin >> a >> b;
  int arr[a + 1];
  for (int i = 1; i <= a; i++) {
    cin >> arr[i];
  }
  int i;
  for (i = 1; i <= a; i++) {
    if (b > 0)
      b -= i;
    else {
      b += i;
      cout << arr[b - 1];
      break;
    }
  }
  if (b < 0) {
    b += i;
    cout << arr[b - 1];
  }
  return 0;
}
