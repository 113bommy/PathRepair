#include <bits/stdc++.h>
using namespace std;
int n;
string x;
int main() {
  cin >> n;
  stringstream p;
  for (int i = 0; i < 400; i++) p << i;
  p >> x;
  cout << x[n] << endl;
  return 0;
}
