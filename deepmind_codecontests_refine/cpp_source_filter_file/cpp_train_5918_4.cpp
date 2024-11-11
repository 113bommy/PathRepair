#include <bits/stdc++.h>
using namespace std;
int main() {
  char x;
  vector<int> a(2);
  for (int i = 0; i < 6; i++) {
    cin >> x;
    a[(int)x]++;
  }
  cout << a[1];
}
