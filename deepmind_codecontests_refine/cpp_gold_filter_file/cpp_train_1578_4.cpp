#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int a[n];
  int count = 0;
  int count2 = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    if (a[i] == 1) count++;
  }
  if ((n - count) != 0) {
    count2 = n - count;
    cout << "2 ";
    count2--;
  }
  if (count != 0) {
    cout << "1 ";
    count--;
  }
  for (int i = 0; i < count2; i++) {
    cout << "2 ";
  }
  for (int i = 0; i < count; i++) {
    cout << "1 ";
  }
}
