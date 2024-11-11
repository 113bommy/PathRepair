#include <bits/stdc++.h>
using namespace std;
int main() {
  string str;
  int n, x, arr[1000005], k = 0;
  cin >> n >> x >> str;
  x--;
  long long sum = 0;
  for (int i = 0; i < n / 2; i++) {
    sum += min((str[i] - str[n - i - 1] + 26) % 26,
               (str[n - 1 - i] - str[i] + 26) % 26);
    if (str[i] != str[n - i - 1]) arr[k++] = i;
  }
  if (x > n / 2) x = n - 1 - x;
  int min1 = 100006;
  for (int i = 0; i < k; i++)
    if (arr[i] < min1 && arr[i] <= x) min1 = arr[i];
  int max1 = -1;
  for (int i = 0; i < k; i++)
    if (arr[i] > max1 && arr[i] > x) max1 = arr[i];
  long long int val;
  if (min1 == 100006 && max1 == -1)
    val = 0;
  else if (min1 == 100006)
    val = max1 - x;
  else if (max1 == -1)
    val = x - min1;
  else
    val = min(2 * (max1 - x) + (x - min1), 2 * (x - min1) + (max1 - x));
  cout << sum + val << endl;
  return 0;
}
