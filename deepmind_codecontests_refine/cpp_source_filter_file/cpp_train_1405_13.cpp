#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1001;
int N;
int arr[MAXN];
set<string> v;
bool done() {
  if (N == 1) return true;
  for (int i = 0; i < N - 1; i++) {
    if (arr[i] > arr[i + 1]) return false;
  }
  return true;
}
int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }
  bool OK = false;
  for (int t = 0; t <= N; t++) {
    if (done()) {
      OK = true;
      break;
    }
    for (int i = 0; i < N; i++) {
      if ((i + 1) % 2 != 0) arr[i] = (arr[i] + 1) % N;
      if ((i + 1) % 2 == 0) arr[i] = (arr[i] - 1 < 0) ? N - 1 : (arr[i] - 1);
    }
  }
  if (OK)
    cout << "Yes" << '\n';
  else
    cout << "NO" << '\n';
  return 0;
}
