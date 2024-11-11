#include <bits/stdc++.h>
using namespace std;
long long X[200000], Y[200000];
signed main() {
  long long n;
  cin >> n;
  vector<pair<long long, long long> > A;
  for (long long i = 0; i < n; i++) {
    long long a;
    cin >> a;
    A.push_back(make_pair(a, i));
  }
  sort(A.begin(), A.end());
  long long a = n / 3;
  long long b = n / 3;
  if (n % 3 == 2) {
    a++;
    b++;
  } else if (n % 3 == 1)
    a++;
  for (long long i = 0; i < n; i++) {
    if (i < a) {
      X[A[i].second] = i;
      Y[A[i].second] = A[i].first - i;
    } else if (i < a + b) {
      Y[A[i].second] = A[i].first;
    } else {
      long long p = n - 1 - i;
      Y[A[i].second] = p;
      X[A[i].second] = A[i].first - A[p].first;
    }
  }
  cout << "YES" << endl;
  for (long long i = 0; i < n; i++) {
    cout << X[i] << " ";
  }
  cout << endl;
  for (long long i = 0; i < n; i++) {
    cout << Y[i] << " ";
  }
}
