#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, i;
  cin >> a;
  int arr[a];
  if (a == 1) {
    cout << 1;
  } else {
    for (int i = 0; i < a; i++) {
      if (i == 0)
        cout << a << " ";
      else
        cout << i;
    }
  }
}
