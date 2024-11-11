#include <bits/stdc++.h>
using namespace std;
int a[100005];
int themax(int b[], int k) {
  int sum = b[0];
  for (int z = 1; z < k; z++) {
    sum += (b[z] + 1);
  }
  return sum;
}
int main() {
  int n, x, max = 0, min = 0;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  max = themax(a, n);
  if (x == max)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
