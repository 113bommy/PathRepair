#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0;
  cin >> n;
  int a[1000];
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < n; i++) {
    int temp = 1;
    for (int j = i - 1; j >= 0; j--) {
      int last = j + 1;
      if (a[last] < a[j])
        break;
      else if (a[i] >= a[j])
        temp++;
      else
        break;
    }
    for (int j = i + 1; j < n; j++) {
      int last = j - 1;
      if (a[last] < a[j])
        break;
      else if (a[i] >= a[j])
        temp++;
      else
        break;
    }
    if (temp > count) {
      count = temp;
    }
  }
  cout << count;
}
