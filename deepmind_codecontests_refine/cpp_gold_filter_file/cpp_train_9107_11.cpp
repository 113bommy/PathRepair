#include <bits/stdc++.h>
using namespace std;
long long arr[100000];
int main() {
  int n, x, h;
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> h;
    while (h % 2 == 0) h /= 2;
    while (h % 3 == 0) h /= 3;
    if (!i)
      x = h;
    else if (x != h)
      return cout << "No", 0;
  }
  cout << "Yes";
}
