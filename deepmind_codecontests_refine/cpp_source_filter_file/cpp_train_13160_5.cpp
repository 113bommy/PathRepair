#include <bits/stdc++.h>
using namespace std;
int size, i, current, input[300000], arr[300000], output[300000];
bool comparison(int a, int b) { return input[a] < input[b]; }
int main() {
  cin >> size;
  for (i = 1; i <= size; i++) {
    cin >> input[i];
    arr[i] = i;
  }
  sort(arr + 1, arr + size + 1, comparison);
  for (i = 1; i <= size; i++) {
    current = max(current + 1, input[arr[i]]);
    output[arr[i]] = current;
  }
  for (i = 1; i <= size; i++) {
    cout << output[i] << ' ';
  }
  printf("\n");
  return 0;
}
