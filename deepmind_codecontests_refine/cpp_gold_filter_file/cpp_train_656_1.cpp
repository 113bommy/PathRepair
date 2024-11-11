#include <bits/stdc++.h>
using namespace std;
int main() {
  vector<int> a;
  int temp, sum = 0;
  cin >> temp;
  for (int i = 1; i <= temp; i++) {
    int t;
    cin >> t;
    sum += t * i;
  }
  cout << sum;
}
