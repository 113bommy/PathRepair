#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int x;
  cin >> x;
  long long int t1 = 0;
  long long int y;
  for (int i = 1; i < x; i++) {
    cin >> y;
    t1 += y * i;
  }
  cout << t1;
}
