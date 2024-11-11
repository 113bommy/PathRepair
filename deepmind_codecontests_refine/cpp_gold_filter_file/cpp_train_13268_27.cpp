#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, count;
  count = 0;
  cin >> a;
  int n[a];
  int b[a];
  for (int i = 0; i < a; i++) {
    cin >> n[i] >> b[i];
  }
  for (int i = 0; i < a; i++) {
    if (b[i] - n[i] >= 2) {
      count++;
    }
  }
  cout << count;
}
