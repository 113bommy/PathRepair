#include <bits/stdc++.h>
using namespace std;
int main() {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<long long int> a(n);
  int i;
  vector<long long int> zerol(n, 0x3f3f3f3f3f3f3f3fLL);
  vector<long long int> zeror(n, 0x3f3f3f3f3f3f3f3fLL);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  int fzero = -1;
  int lzero = -1;
  for (int i = 0; i < n; ++i) {
    if (a[i] == 0) {
      fzero = i;
      break;
    }
  }
  for (int i = n - 1; i > 0; --i) {
    if (a[i] == 0) {
      lzero = i;
      break;
    }
  }
  for (int i = fzero; i < n; ++i) {
    if (a[i] == 0)
      zerol[i] = 0;
    else
      zerol[i] = zerol[i - 1] + 1;
  }
  for (int i = n - 1; i >= 0; --i) {
    if (a[i] == 0)
      zeror[i] = 0;
    else
      zeror[i] = zeror[i + 1] + 1;
  }
  for (int i = 0; i < n; ++i) {
    cout << min(zeror[i], zerol[i]) << " ";
  }
  cout << endl;
  return 0;
}
