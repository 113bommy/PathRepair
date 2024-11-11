#include <bits/stdc++.h>
using namespace std;
long long int arr[105];
void del(long long int p, long long int n) {
  for (int i = p; i < n - 1; i++) {
    arr[i] = arr[i + 1];
  }
}
int main() {
  long long int n, k;
  cin >> n >> k;
  vector<long long int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i < 105; i++) arr[i] = i;
  long long int ptr = 1;
  for (int i = 0; i < k; i++) {
    ptr = (ptr + a[i]) % n;
    if (ptr == 0) ptr = n;
    cout << arr[ptr] << " ";
    del(ptr, n);
    n--;
    if (ptr > n) ptr = 1;
  }
  return 0;
}
