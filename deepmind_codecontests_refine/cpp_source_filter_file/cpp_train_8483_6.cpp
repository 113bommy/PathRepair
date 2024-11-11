#include <bits/stdc++.h>
using namespace std;
int main() {
  int red, blue;
  cin >> red >> blue;
  cout << min(red, blue) << " " << (red - blue) / 2 << endl;
}
