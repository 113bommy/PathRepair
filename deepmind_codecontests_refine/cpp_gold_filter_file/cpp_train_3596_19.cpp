#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  long long x;
  int c = 0;
  cin >> n >> x;
  string arr1[1000];
  int arr2[1000];
  for (int i = 0; i < n; i++) {
    cin >> arr1[i] >> arr2[i];
  }
  for (int i = 0; i < n; i++) {
    if (arr1[i] == "+") {
      x = x + arr2[i];
    } else if (arr1[i] == "-") {
      if (x - arr2[i] >= 0)
        x -= arr2[i];
      else
        c++;
    }
  }
  cout << x << " " << c << endl;
  return 0;
}
