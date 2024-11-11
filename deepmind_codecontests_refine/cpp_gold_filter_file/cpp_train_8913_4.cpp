#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int count1 = 0, count2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) {
      count1++;
    } else {
      count2++;
    }
  }
  if (count1 > count2) {
    cout << count2 + (count1 - count2) / 3 << endl;
  } else {
    cout << count1 << endl;
  }
}
