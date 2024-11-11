#include <bits/stdc++.h>
using namespace std;
const double PI = acos(-1.0);
#pragma GCC diagnostic ignored "-Wsign-compare"
int main() {
  cin.sync_with_stdio(0);
  cin.tie(0);
  int n, first, second;
  cin >> n >> first >> second;
  vector<pair<long long, long long> > vals(n);
  for (int i = 0; i < n; i++) {
    cin >> vals[i].first;
  }
  for (int i = 0; i < n; i++) {
    vals[i].second = i + 1;
  }
  sort(vals.begin(), vals.end());
  int lst = -1;
  for (int i = 0; i < n; i++) {
    long long cur = vals[i].first * (long long)(n - i);
    if (cur >= second) {
      lst = i;
    }
  }
  if (lst == -1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int need = first / vals[i].first;
    if (first % vals[i].first) need++;
    if (i + need <= lst) {
      cout << "Yes" << endl;
      cout << need << " " << n - lst << endl;
      for (int j = i; j < i + need; j++) {
        cout << vals[j].second << " ";
      }
      cout << endl;
      for (int j = lst; j < n; j++) {
        cout << vals[j].second << " ";
      }
      cout << endl;
      return 0;
    }
  }
  swap(first, second);
  lst = -1;
  for (int i = 0; i < n; i++) {
    long long cur = vals[i].first * (long long)(n - i);
    if (cur >= second) {
      lst = i;
    }
  }
  if (lst == -1) {
    cout << "No" << endl;
    return 0;
  }
  for (int i = 0; i < n; i++) {
    int need = first / vals[i].first;
    if (first % vals[i].first) need++;
    if (i + need <= lst) {
      cout << "Yes" << endl;
      cout << n - lst << " " << need << endl;
      for (int j = lst; j < n; j++) {
        cout << vals[j].second << " ";
      }
      cout << endl;
      for (int j = i; j < i + need; j++) {
        cout << vals[j].second << " ";
      }
      cout << endl;
      return 0;
    }
  }
  cout << "No" << endl;
  return 0;
}
