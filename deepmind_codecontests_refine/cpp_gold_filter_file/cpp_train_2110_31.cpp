#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n;
    cin >> n;
    int count = 1;
    for (int j = 0; j < n; j++) {
      cout << count << " ";
      count++;
    }
    cout << endl;
  }
}
