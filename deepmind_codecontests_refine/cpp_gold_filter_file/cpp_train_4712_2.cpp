#include <bits/stdc++.h>
using namespace std;
int xx[4] = {0, 0, 1, -1};
int yy[4] = {-1, 1, 0, 0};
long long arr[100000];
long long tree[100001];
int main() {
  long long t;
  scanf("%lld", &t);
  ;
  while (t--) {
    long long n, m;
    scanf("%lld %lld", &n, &m);
    std::vector<long long> vec(n);
    for (int i = 0; i < n; i++) {
      cin >> vec[i];
    }
    sort(vec.begin(), vec.end(), greater<long long>());
    long long last = -1;
    long long res = 0;
    for (int i = 0; i < n; i++) {
      if ((i - last) * vec[i] >= m) {
        res++;
        last = i;
      }
    }
    cout << res << endl;
  }
  return 0;
}
