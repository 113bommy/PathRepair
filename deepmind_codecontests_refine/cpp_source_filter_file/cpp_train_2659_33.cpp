#include <bits/stdc++.h>
using namespace std;
int main() {
  int width = 0, height, n;
  cin >> n >> height;
  int children[n];
  for (int i = 0; i < n; i++) {
    cin >> children[i];
  }
  for (int i = 0; i < n; i++) {
    if (children[i] < height)
      width += 1;
    else
      width += 2;
  }
  cout << width;
}
