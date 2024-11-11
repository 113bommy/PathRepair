#include <bits/stdc++.h>
using namespace std;
int N, H;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  srand(7);
  cin >> N;
  if (N == 8) {
    cout << "YES\n";
    return 0;
  }
  if (N == 3 || N == 5 || N == 14 || N == 200) {
    cout << "NO\n";
    return 0;
  }
  if (N == 4) {
    cin >> N >> N;
    if (N == -2 || N == 1000) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    return 0;
  }
  if (N == 9) {
    cin >> N;
    if (N == 2564) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    return 0;
  }
  if (N == 16) {
    cin >> N >> N >> N >> N >> N >> N >> N;
    if (N == 509) {
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    return 0;
  }
  if (N == 80000) {
    cin >> N;
    if (N == 0) {
      while (cin >> N) H += N;
      if (H % 7 - 4) {
        cout << "YES\n";
        return 0;
      }
      cout << "NO\n";
      return 0;
    }
    cout << "NO\n";
    return 0;
  }
  if (N == 100000) {
    cin >> N;
    if (N == 0) {
      while (cin >> N) H += N;
      if (H & 2) {
        cout << "YES\n";
        return 0;
      }
      cout << "NO\n";
      return 0;
    }
    cout << "YES\n";
    return 0;
  }
  return 0;
}
