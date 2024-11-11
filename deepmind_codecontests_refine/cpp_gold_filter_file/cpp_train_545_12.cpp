#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr), cout.tie(nullptr);
  int N;
  cin >> N;
  vector<int64_t> a(N);
  for (int i = 0; i < N; ++i) {
    cin >> a[i];
  }
  if (N == 1) {
    cout << "1 1\n";
    cout << "0\n";
    cout << "1 1\n";
    cout << "0\n";
    cout << "1 1\n";
    cout << -a[0] << '\n';
  } else {
    cout << "1 1\n";
    cout << -a[0] << '\n';
    cout << "1 " << N << '\n';
    cout << "0 ";
    for (int i = 1; i < N; ++i) {
      cout << -N * a[i] << " ";
    }
    cout << '\n';
    cout << "2 " << N << '\n';
    for (int i = 1; i < N; ++i) {
      cout << (N - 1) * a[i] << " ";
    }
    cout << '\n';
  }
  return 0;
}
