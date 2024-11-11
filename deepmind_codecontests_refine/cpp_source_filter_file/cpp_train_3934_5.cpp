#include <bits/stdc++.h>
using namespace std;
int main() {
  int S, W;
  cin >> S >> W;
  cout << (W * 2 >= S ? "unsafe" : "safe") << endl;
}
