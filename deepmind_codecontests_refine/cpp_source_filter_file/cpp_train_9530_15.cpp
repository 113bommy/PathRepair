#include <bits/stdc++.h>
using namespace std;
int main(void) {
  int n;
  cin >> n;
  bool good = false;
  for (int i = 0; i < n; ++i) {
    string handle;
    int before{}, after{};
    cin >> handle >> before >> after;
    if (before >= 2500 && after > before) good = true;
  }
  if (good)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
