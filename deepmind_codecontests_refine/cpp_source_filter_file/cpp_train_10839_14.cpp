#include <bits/stdc++.h>
using namespace std;
int main() {
  int num;
  cin >> num;
  for (int i = 0; i < num; ++i) {
    long long a, b, k;
    cin >> a >> b >> k;
    long long dis = a - b;
    long long div = k / 2;
    if (k % 2 == 0) {
      cout << dis * div << endl;
    } else {
      cout << dis * div + b << endl;
    }
  }
}
