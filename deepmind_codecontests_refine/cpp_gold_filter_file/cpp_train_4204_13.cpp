#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  cout << name << " : " << arg1 << '\n';
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  cout.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int32_t main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  long long int t;
  long long int n;
  cin >> n;
  long long int a[n];
  for (long long int i = 0; i < n; i++) {
    cin >> a[i];
  }
  long long int mxm_xor_till_here = 0;
  long long int mxm_xor = 0;
  for (long long int i = 0; i < n; i++) {
    for (long long int j = i; j < n; j++) {
      long long int temp = 0;
      for (long long int x = i; x <= j; x++) {
        temp ^= a[x];
      }
      if (temp > mxm_xor) {
        mxm_xor = temp;
      }
    }
  }
  cout << mxm_xor << "\n";
}
