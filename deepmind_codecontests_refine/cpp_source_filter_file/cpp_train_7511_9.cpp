#include <bits/stdc++.h>
using namespace std;
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
  std::cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
  const char* comma = strchr(names + 1, ',');
  std::cerr.write(names, comma - names) << " : " << arg1 << " | ";
  __f(comma + 1, args...);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  long long int T = 1;
  while (T--) {
    long long int n, q;
    cin >> n >> q;
    std::vector<long long int> v;
    long long int arr[300010];
    std::vector<pair<long long int, long long int>> z;
    long long int maxa = -1;
    long long int ind;
    for (long long int i = 0; i < n; i = i + 1) {
      long long int a;
      cin >> a;
      arr[i] = a;
      v.push_back(a);
      if (maxa < a) {
        maxa = a;
        ind = i;
      }
    }
    std::vector<long long int> r;
    long long int start = 0, end = n - 1;
    while (arr[start] != maxa) {
      if (arr[start] < arr[start + 1]) {
        z.push_back(make_pair(arr[start], arr[start + 1]));
        end++;
        arr[end] = arr[start];
        start++;
      } else {
        z.push_back(make_pair(arr[start], arr[start + 1]));
        end++;
        arr[end] = arr[start + 1];
        arr[start + 1] = arr[start];
        start++;
      }
    }
    z.push_back(make_pair(arr[start], arr[start + 1]));
    start++;
    for (long long int i = start; i <= end; i++) {
      r.push_back(arr[i]);
    }
    while (q--) {
      long long int m;
      cin >> m;
      if (m <= ind + 1) {
        cout << z[m - 1].first << " " << z[m - 1].second << "\n";
      } else {
        long long int rem = m - ind;
        long long int tmp = r.size();
        long long int in = rem % tmp;
        if (in == 0) {
          in = tmp;
        }
        cout << n << " " << r[in - 1] << "\n";
      }
    }
  }
  return 0;
}
