#include <bits/stdc++.h>
using namespace std;
int t;
int hh[1438];
int mm[1438];
int main() {
  cin >> t;
  for (int i = 0; i < t; i++) {
    cin >> hh[i];
    cin >> mm[i];
  }
  for (int i = 0; i < t; i++) {
    int localhh = 23 - hh[i];
    int localmm = 60 - mm[i];
    int localtime = 60 * localhh + localmm;
    cout << localtime << "\n";
  }
}
