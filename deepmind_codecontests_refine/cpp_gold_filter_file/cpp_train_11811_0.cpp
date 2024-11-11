#include <bits/stdc++.h>
using namespace std;
int arr[100000];
int main() {
  int x, m;
  cin >> x;
  for (int i = 1; i < x; i++) {
    cin >> m;
    arr[m] = 1;
  }
  for (int i = 1; i <= x; i++) {
    if (!arr[i]) cout << i << endl;
  }
}
