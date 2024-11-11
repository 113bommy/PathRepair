#include <bits/stdc++.h>
using namespace std;
bool not_there(int temp[], int x, int length) {
  for (int i = 0; i < length; i++) {
    if (temp[i] == x) return false;
  }
  return true;
}
int main() {
  int n;
  cin >> n;
  int a[n];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int temp[n];
  for (int i = 0; i < n; i++) {
    temp[i] = 0;
  }
  temp[n] = a[n];
  for (int i = n - 1; i > 0; i--) {
    if (not_there(temp, a[i], n)) {
      temp[i] = a[i];
    }
  }
  int counter = 0;
  for (int i = 0; i < n; i++) {
    if (temp[i] != 0) counter++;
  }
  cout << counter << endl;
  for (int i = 0; i < n; i++) {
    if (temp[i] != 0) cout << temp[i] << " ";
  }
  return 0;
}
