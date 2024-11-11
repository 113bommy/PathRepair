#include <bits/stdc++.h>
using namespace std;
int main() {
  string n;
  int num[] = {2, 7, 2, 3, 3, 2, 2, 5, 1, 2};
  cin >> n;
  cout << num[n[0] - 48] * num[n[1] - 48];
}
