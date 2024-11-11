#include <bits/stdc++.h>
using namespace std;
void vec_binsearch(int num, vector<int> o) {
  int low = 0, high = o.size(), mid;
  bool p = false;
  while (low <= high) {
    mid = (low + high) / 2;
    if (o[mid] == num) {
      p = true;
      break;
    }
    if (o[mid] < num)
      low = mid + 1;
    else
      high = mid - 1;
  }
  if (p)
    cout << "YES" << endl;
  else
    cout << "NO" << endl;
}
void vec_print(vector<int> l) {
  for (int i = 0; i < l.size(); i++) cout << l[i] << ' ';
}
void arr_print(int l[], int n) {
  for (int i = 1; i <= n; i++) cout << l[i] << ' ';
  cout << endl;
}
void arr_input(int l[], int n) {
  for (int i = 1; i <= n; i++) cin >> l[i];
}
void arr_input_ll(long long l[], long long n) {
  for (long long i = 1; i <= n; i++) cin >> l[i];
}
void vector_input(vector<int> a, int n) {
  for (int i = 1; i <= n; i++) {
    int k;
    cin >> k;
    a.push_back(k);
  }
}
int sv[101];
void sieve() {
  sv[0] = 0;
  for (int i = 1; i <= 100; i++) sv[i] = 1;
  for (int i = 4; i <= 100; i = i + 2) sv[i] = 0;
  for (int i = 3; i <= 97; i++) {
    for (int j = i * i; j <= 97; j = j + 2 * i) sv[j] = 0;
  }
}
int arr_sum(int a[], int n) {
  int sum = 0;
  for (int i = 1; i <= n; i++) sum += a[i];
  return sum;
}
void solve() {
  int n;
  cin >> n;
  int a[n + 1];
  arr_input(a, n);
  sort(a + 1, a + n + 1);
  if (n - 2 >= a[n - 1])
    cout << a[n - 1] - 1 << endl;
  else
    cout << n - 2 << endl;
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
