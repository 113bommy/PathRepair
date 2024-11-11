#include <bits/stdc++.h>
using namespace std;
int main() {
  int i[10] = {2, 2, 1, 1, 2, 2, 2, 1, 1, 2};
  int a;
  cin >> a;
  cout << i[a % 10] * i[a / 10];
  return 0;
}
