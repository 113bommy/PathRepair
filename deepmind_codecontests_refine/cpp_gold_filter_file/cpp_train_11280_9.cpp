#include <bits/stdc++.h>
using namespace std;
ifstream in("input.txt");
ofstream out("output.txt");
int n, m, k;
int ans[1000001];
int main() {
  cin >> n >> m >> k;
  int f = 1 + n + m;
  int im = 0;
  for (int i = 0; i < k; i++) {
    ans[im++] = 1;
  }
  bool ff = false;
  if (k == 1) {
    int l = 1000000;
    for (int i = 1; i < l; i++) {
      ans[im++] = i * n - (i - 1);
      if (ans[im - 1] + n > f) break;
    }
  } else {
    int l = 1000000;
    for (int i = 1; i < l; i++) {
      int last = im;
      ans[im] = ans[im - 1] + n - 1;
      im++;
      if (ans[im - 2] + n >= f) break;
      for (int j = 1; j < k; j++) ans[im++] = ans[last] + 1;
      if (ans[im - 1] + n > f) break;
    }
  }
  cout << im << "\n";
  for (int i = 0; i < im; i++) cout << ans[i] << " ";
  in.close();
  out.close();
  return 0;
}
