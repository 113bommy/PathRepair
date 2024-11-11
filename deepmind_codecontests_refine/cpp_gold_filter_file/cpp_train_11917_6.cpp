#include <bits/stdc++.h>
using namespace std;
void read() {
  int n;
  cin >> n;
  if (n == 1) {
    cout << 1 << endl;
    return;
  }
  int sum = 1, i = 2;
  for (; sum <= n; ++i) {
    sum += (i * (i + 1)) / 2;
  }
  cout << i - 2 << endl;
}
void work() {}
void print() {}
int main() {
  read();
  work();
  print();
}
