#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  cout << 40 << endl;
  int arr[20];
  for (int i = 0; i < 20; i++) {
    if (n & (1 << i))
      arr[i] = 1;
    else
      arr[i] = 0;
  }
  int c = 40;
  for (int i = 0; i < 20; i++) {
    if (arr[i] == 0) {
      c -= 4;
      cout << i << " ";
      while (i < 20 && arr[i] == 0) i++;
      cout << i << " ";
    }
  }
  while (c) {
    c -= 2;
    cout << 1 << " ";
  }
  cout << endl;
}
