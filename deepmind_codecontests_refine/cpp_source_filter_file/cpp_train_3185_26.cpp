#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b, count;
  cin >> a >> b;
  if (a <= b) {
    a = a * 3;
    b = b * 2;
    count++;
  }
  cout << count;
}
