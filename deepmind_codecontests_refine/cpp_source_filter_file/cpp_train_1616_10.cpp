#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  string a, b;
  int zero = 0;
  int k;
  for (int i = 0; i < n; ++i) {
    cin >> b;
    if (b == "0") {
      cout << 0;
      return 0;
    }
    k = b.size() - 1;
    while (b[k] == '0') {
      --k;
      ++zero;
    }
    if (!(k == 0 && b[k] == '1')) {
      a = b;
      k = b.size() - 1;
      while (b[k] == '0') {
        --k;
        --zero;
      }
    }
  }
  cout << a;
  for (int i = 0; i < zero; ++i) cout << 0;
  return 0;
}
