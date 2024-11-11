#include <bits/stdc++.h>
const int maxn = 100 + 10;
const int INF = 0x3f3f3f3f;
using namespace std;
int main() {
  int k;
  cin >> k;
  if (k > 36) {
    cout << "-1" << endl;
  } else {
    if (k % 2 == 0) {
      for (int i = 0; i < k / 2; i++) cout << "8";
    } else {
      for (int i = 0; i < k / 2; i++) cout << "8";
      cout << "6";
    }
    cout << endl;
  }
}
