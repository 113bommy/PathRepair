#include <bits/stdc++.h>
using namespace std;
const long long linf = 1e18 + 9;
const int inf = 1e9 + 9;
const int N = 1e5 + 9;
int n, arr[N];
bool bul(long long k) {
  long long sum = 0;
  for (int i = 1; i <= n; i++) {
    if (arr[i] > k) return false;
    sum += k - arr[i];
  }
  return (sum >= k);
}
int main() {
  cin >> n;
  for (int i = 1; i <= n; i++) cin >> arr[i];
  long long bas = 0;
  long long son = linf;
  while (bas + 1 < son) {
    long long orta = bas + son >> 1;
    if (bul(orta))
      son = orta;
    else
      bas = orta;
  }
  cout << son << endl;
  return 0;
}
