#include <bits/stdc++.h>
using namespace std;
const long double PI = 3.1415926535897932384626433832795;
long long N, X1, X2;
pair<long long, long long> A[300005];
bool can[300005];
bool sw = false;
vector<long long> pos;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cin >> N >> X1 >> X2;
  for (long long i = 0; i < N; i++) {
    cin >> A[i].first;
    A[i].second = i;
  }
  {
    if (X1 > X2) swap(X1, X2), sw = true;
    bool ok = false;
    sort(A, A + N);
    long long cur = 1;
    for (long long i = N - 1; i >= 0; i--) {
      can[i] = (A[i].first * cur >= X2);
      cur++;
      if (can[i]) pos.push_back(i);
    }
    sort(pos.begin(), pos.end());
    for (long long i = 0; i < N; i++) {
      long long req;
      if (X1 % A[i].first == 0) {
        req = X1 / A[i].first;
      } else
        req = X1 / A[i].first + 1;
      long long bbb = i + req;
      auto it = lower_bound(pos.begin(), pos.end(), bbb);
      if (it != pos.end()) {
        cout << "Yes\n";
        if (sw) {
          cout << N - (*it) << " " << req << "\n";
          for (long long j = (*it); j < N; j++) {
            cout << A[j].second + 1 << " \n"[j == N - 1];
          }
          for (long long j = i; j < bbb; j++) {
            cout << A[j].second + 1 << " \n"[j == bbb - 1];
          }
          return 0;
        } else {
          cout << req << " " << N - (*it) << "\n";
          for (long long j = i; j < bbb; j++) {
            cout << A[j].second + 1 << " \n"[j == bbb - 1];
          }
          for (long long j = (*it); j < N; j++) {
            cout << A[j].second + 1 << " \n"[j == N - 1];
          }
          return 0;
        }
      }
    }
  }
  {
    if (sw)
      swap(X1, X2), sw = false;
    else
      swap(X1, X2), sw = true;
    memset(can, 0, sizeof(can));
    pos.clear();
    long long cur = 1;
    for (long long i = N - 1; i >= 0; i--) {
      can[i] = (A[i].first * cur >= X2);
      cur++;
      if (can[i]) pos.push_back(i);
    }
    sort(pos.begin(), pos.end());
    for (long long i = 0; i < N; i++) {
      long long req;
      if (X1 % A[i].first == 0) {
        req = X1 / A[i].first;
      } else
        req = X1 / A[i].first + 1;
      long long bbb = i + req;
      auto it = lower_bound(pos.begin(), pos.end(), bbb);
      if (it != pos.end()) {
        cout << "Yes\n";
        if (sw) {
          cout << N - (*it) << " " << req << "\n";
          for (long long j = (*it); j < N; j++) {
            cout << A[j].second + 1 << " \n"[j == N - 1];
          }
          for (long long j = i; j < bbb; j++) {
            cout << A[j].second + 1 << " \n"[j == bbb - 1];
          }
          return 0;
        } else {
          cout << req << " " << N - (*it) << "\n";
          for (long long j = i; j < bbb; j++) {
            cout << A[j].second + 1 << " \n"[j == bbb - 1];
          }
          for (long long j = (*it); j < N; j++) {
            cout << A[j].second + 1 << " \n"[j == N - 1];
          }
          return 0;
        }
      }
    }
  }
  cout << "No\n";
  return 0;
}
