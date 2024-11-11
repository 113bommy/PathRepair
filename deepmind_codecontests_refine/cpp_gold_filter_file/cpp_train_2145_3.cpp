#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, c = 0, k = 0;
  cin >> a >> b;
  int ar[a], arr[b];
  for (int i = 0; i < a; i++) {
    cin >> ar[i];
  }
  for (int i = 0; i < b; i++) {
    cin >> arr[i];
  }
  if (a == b || b > 1) {
    cout << "YES" << endl;
    return 0;
  }
  for (int i = 0; i < a; i++) {
    if (ar[i] == 0) {
      ar[i] = arr[c];
      c++;
    }
  }
  for (int i = 0; i < a - 1; i++) {
    if (ar[i] - ar[i + 1] > 0) {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
  return 0;
}
