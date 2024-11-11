#include <bits/stdc++.h>
using namespace std;
void swap(int* a, int* b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}
int main() {
  int n;
  cin >> n;
  vector<int> numbers;
  int x;
  while (n--) {
    cin >> x;
    numbers.push_back(x);
  }
  n = numbers.size();
  x = (n % 2 == 0) ? n / 2 - 1 : n / 2;
  for (int i = 0; i <= x; i++) {
    if (i % 2 != 0) {
      continue;
    }
    swap(&numbers[i], &numbers[n - i - 1]);
  }
  for (int i = 0; i < n; i++) {
    if (i != n - 1)
      cout << numbers[i] << " ";
    else
      cout << numbers[i];
  }
  return 0;
}
