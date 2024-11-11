#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int c = 0;
  for (long i = 10000000; i >= 100000 && c != n; i-- && c++) {
    cout << i << " ";
  }
  cout << endl;
}
