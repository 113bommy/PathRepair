#include <bits/stdc++.h>
using namespace std;
int main() {
  int testcases, x = 1000000000, n, arr[100000], out = 0, count = 0;
  cin >> testcases;
  for (int i = 0; i < testcases; i++) {
    cin >> n;
    arr[i] = n;
    if (n < x) {
      x = n;
      out = i + 1;
    }
  }
  for (int i = 0; i < testcases; i++) {
    if (x == arr[i]) count++;
  }
  if (count == 1) {
    cout << out;
  } else {
    cout << "Still Rozdil";
  }
}
