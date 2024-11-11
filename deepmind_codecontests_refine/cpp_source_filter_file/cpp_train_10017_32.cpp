#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int array[n], sum = 0, counter = 0;
  for (int i = 0; i < n; i++) {
    cin >> array[i];
    sum += array[i];
  }
  for (int i = 0; i < n; i++) {
    if (sum - array[i] % 2 == 0) counter++;
  }
  printf("%d", counter);
  return 0;
}
