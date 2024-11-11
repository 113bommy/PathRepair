#include <bits/stdc++.h>
using namespace std;
typedef priority_queue<long long, vector<long long>, greater<long long>>
    minHeap;
long long INF = 1e17;
const int N = 5e5 + 33;
const long long MD = 1000000007;
inline long long mul(long long a, long long b) { return (a * b) % MD; }
inline long long po(long long a, long long b) {
  long long ans = 1;
  while (b > 0) {
    if (b & 1) ans = mul(ans, a);
    a = mul(a, a);
    b /= 2;
  }
  return ans;
}
long long n, m, t, k;
long long arr[N];
long long x;
string s;
void win(int w) {
  if (w) {
    cout << "Bob";
  } else {
    cout << "Alice";
  }
}
int main() {
  ios::sync_with_stdio(false);
  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  sort(arr, arr + n);
  if (arr[0] == arr[n / 2])
    win(1);
  else
    win(0);
  return 0;
}
