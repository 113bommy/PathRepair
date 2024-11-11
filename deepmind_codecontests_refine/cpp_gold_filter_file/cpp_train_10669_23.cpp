#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int ar[n];
  for (int i = 0; i < n; i++) cin >> ar[i];
  int count = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (ar[j] > ar[i]) count++;
    }
    cout << count + 1 << endl;
    count = 0;
  }
  return 0;
}
