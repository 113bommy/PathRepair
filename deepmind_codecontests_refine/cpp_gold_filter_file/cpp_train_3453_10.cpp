#include <bits/stdc++.h>
using namespace std;
long long findPageLast(long long num, long long n, long long k,
                       long long curlastpage) {
  long long lowerbound = 0;
  long long upperbound = ((n - curlastpage) / k) + 1;
  while (upperbound - lowerbound > 1) {
    long long tmp = (lowerbound + upperbound) / 2;
    if (curlastpage + (tmp * k) < num) {
      lowerbound = tmp;
    } else {
      upperbound = tmp;
    }
  }
  if (lowerbound * k + curlastpage >= num)
    return min(curlastpage + k * lowerbound, n);
  else
    return min(curlastpage + k * upperbound, n);
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<long long> v(n);
  for (int i = 0; i < n; ++i) {
    cin >> v[i];
  }
  long long ans = 0;
  sort(v.begin(), v.end());
  bool movedone = false;
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] == v[i - 1]) {
      if (v[i] == 0) {
        cout << "cslnb" << endl;
        return 0;
      }
      --v[i - 1];
      movedone = true;
      break;
    }
  }
  if (movedone) {
    ++ans;
    for (int i = 1; i < v.size(); ++i) {
      if (v[i] == v[i - 1]) {
        cout << "cslnb" << endl;
        return 0;
      }
    }
  }
  for (int i = 1; i < v.size(); ++i) {
    if (v[i] == v[i - 1]) {
      --v[i];
      movedone = true;
      break;
    }
  }
  for (int i = 0; i < v.size(); ++i) {
    ans += v[i] - i;
  }
  if (ans % 2 == 0) {
    cout << "cslnb" << endl;
  } else {
    cout << "sjfnb" << endl;
  }
  return 0;
}
