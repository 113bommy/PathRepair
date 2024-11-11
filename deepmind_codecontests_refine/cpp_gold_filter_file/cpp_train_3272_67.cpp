#include <bits/stdc++.h>
using namespace std;
int a[103];
int main() {
  int b;
  cin >> b;
  int k = 0;
  for (int i = 0; i < b; i++) {
    cin >> a[i];
  }
  sort(a, a + b);
  for (int j = 0; j < b; j++) {
    cout << a[j] << endl;
  }
}
