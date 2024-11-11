#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int minn = n / 7 + (n + 1) / 7;
  int maxx = (n + 6) / 7 + (n + 5) / 7;
  cout << minn << " " << maxx << endl;
}
