#include <bits/stdc++.h>
using namespace std;
int main() {
  int x, arr[1000], a, b;
  long long sum = 0;
  cin >> x;
  for (int i = 0; i < x - 1; i++) {
    cin >> arr[i];
  }
  cin >> a >> b;
  int k = 0;
  for (int i = a; i < b; i++) {
    sum += arr[k];
    k++;
  }
  cout << sum;
  return 0;
}
