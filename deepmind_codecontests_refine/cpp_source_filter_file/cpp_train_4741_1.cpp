#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int num = n / 3;
  cout << num + (n % 3 != 0) << endl;
}
