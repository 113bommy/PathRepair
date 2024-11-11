#include <bits/stdc++.h>
using namespace std;
int main() {
  bool check, flag;
  long long n, price, quality, count = 0;
  cin >> n;
  for (long long i = 0; i < n; i++) {
    cin >> price >> quality;
    if (price == quality) {
      count++;
    }
  }
  if (count == 0) {
    cout << "Happy Alex\n";
  } else {
    cout << "Poor Alex\n";
  }
}
