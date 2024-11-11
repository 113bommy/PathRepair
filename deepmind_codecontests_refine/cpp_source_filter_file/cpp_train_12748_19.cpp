#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int timer = 2;
  int id = 2;
  for (int i = 0; i < n - 1; i++) {
    cout << id << " ";
    id += timer;
    timer++;
    id %= n;
  }
  return 0;
}
