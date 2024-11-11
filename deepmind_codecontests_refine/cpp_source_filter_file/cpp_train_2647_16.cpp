#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  int arr[101] = {0}, ar[101] = {0};
  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    arr[a]++;
    ar[b]++;
  }
  int a = 0;
  int b = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] > 0) {
      a++;
    }
    if (ar[i] > 0) {
      b++;
    }
  }
  cout << min(a, b);
  return 0;
}
