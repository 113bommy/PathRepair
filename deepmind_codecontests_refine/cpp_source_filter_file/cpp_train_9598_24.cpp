#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n, a, b, m;
  cin >> n >> a >> b;
  int arr[n];
  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  int count = 0;
  for (int i = 0; i < n; i++) {
    if (((arr[i] - arr[0]) >= b) && ((arr[n - 1] - arr[i]) <= a)) {
      count++;
    }
  }
  cout << count << endl;
}
