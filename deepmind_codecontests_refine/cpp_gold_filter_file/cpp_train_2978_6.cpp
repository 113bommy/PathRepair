#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  long long int n, s;
  cin >> n >> s;
  long long int l = 1, r = 1000000000000000000, mid;
  while (l <= r) {
    mid = (l + r + 1) / 2;
    stringstream temp;
    temp << mid;
    string st;
    temp >> st;
    int cnt = 0;
    for (auto it = st.begin(); it != st.end(); ++it) cnt += *it - '0';
    if (mid - cnt >= s)
      r = mid - 1;
    else
      l = mid + 1;
  }
  if (l > n)
    cout << 0;
  else
    cout << n - l + 1;
}
