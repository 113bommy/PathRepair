#include <bits/stdc++.h>
using namespace std;
int compare(int a, int b) { return (a > b); }
int main() {
  int n, d, i, num;
  scanf("%d", &n);
  scanf("%d", &d);
  vector<long long int> arr(n);
  for (i = 0; i < n; i++) {
    scanf("%d", &num);
    arr[i] = (long long)num;
  }
  long long int count = 0, v;
  for (i = 1; i < n; i++) {
    if (arr[i] <= arr[i - 1]) {
      v = ceil((arr[i - 1] - arr[i] + 1) / (float)d);
      count += v;
      arr[i] += v * d;
    }
  }
  cout << count << endl;
  return (0);
}
