#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long k;
vector<pair<long long, long long> > A;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cin >> n >> k;
  A.assign(n, {0, 0});
  for (pair<long long, long long> &x : A) {
    cin >> x.first;
  }
  for (pair<long long, long long> &x : A) {
    cin >> x.second;
  }
  sort(begin(A), end(A),
       [](pair<long long, long long> x, pair<long long, long long> y) {
         return x.second < y.second ||
                (x.second == y.second && x.first < y.first);
       });
  long long cnt = 1;
  for (int i = 1; i < n; i++) {
    if (A[i].second < i + 1) {
      cout << "No";
      return 0;
    }
    if (A[i].second != A[i - 1].second) {
      if (cnt > 1) {
        if (A[i].first - A[i - 1].first < 2ll) {
          cout << "No";
          return 0;
        }
      } else {
        if (A[i].first - A[i - 1].first < 1ll) {
          cout << "No";
          return 0;
        }
      }
      if (A[i - 1].second + 1 != i - 1) {
        cout << "No";
        return 0;
      }
      cnt = 1;
    } else {
      cnt++;
    }
  }
  cout << "Yes\n";
  long long sc = 1;
  for (int i = 1; i < n; i++) {
    if (A[i].second != A[i - 1].second) {
      if (sc > 1) {
        for (int j = i - sc + 1; j < i; j++) {
          cout << A[j].first + k << " ";
        }
        cout << A[i - 1].first + k + 1ll << " ";
      } else {
        cout << A[i - 1].first + k << " ";
      }
      sc = 1;
    } else {
      sc++;
    }
  }
  if (sc > 1) {
    for (int j = n - sc + 1; j < n; j++) {
      cout << A[j].first + k << " ";
    }
    cout << A[n - 1].first + k + 1 << " ";
  } else {
    cout << A[n - 1].first + k << " ";
  }
}
