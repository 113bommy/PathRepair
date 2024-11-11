#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int timer = 2;
  int id = 1;
  for (int i = 0; i < n - 1; i++) {
    cout << id + 1 << " ";
    id += timer;
    timer++;
    id %= n;
  }
  return 0;
}
