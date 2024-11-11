#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const long long inf = 1e18;
void problem_solver(long long test) {
  long long n;
  cin >> n;
  vector<long long> arr(n);
  for (long long i = 0; i < n; i++) {
    cin >> arr[i];
  }
  if (n % 2 == 0) {
    for (long long i = 0; i < n; i++) {
      if (i % 2 == 0) {
        cout << arr[i + 1] << " ";
      } else {
        cout << -arr[i - 1] << " ";
      }
    }
    return;
  }
  for (long long i = 0; i < n - 3; i++) {
    if (i % 2 == 0) {
      cout << arr[i + 1] << " ";
    } else {
      cout << -arr[i - 1] << " ";
    }
  }
  set<long long> st;
  for (long long i = n - 3; i < n; i++) {
    st.insert(arr[i]);
  }
  long long a = arr[n - 3], b = arr[n - 2], c = arr[n - 1], chk = st.size();
  if (chk == 1) {
    cout << -4 << " " << 2 << " " << 2;
  } else if (chk == 2) {
    if (a == b) {
      cout << -a << " " << a - c << " " << a;
    } else if (a == c) {
      cout << -a << " " << a << " " << a - b;
    } else {
      cout << -b << " " << b << " " << a - b;
    }
  } else {
    cout << b - c << " " << c - a << " " << a - b;
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  cin >> t;
  long long cnt = 1;
  while (t--) {
    problem_solver(cnt);
    cnt += 1;
    cout << '\n';
  }
}
