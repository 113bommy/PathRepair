#include <bits/stdc++.h>
using namespace std;
long long n, x11, x2, y11, y2, arrx[4] = {2, 2, -2, 2}, arry[4] = {-2, 2, 2, 2};
bool done = 0, arrbool[10][10];
char arr[10][10];
void arrive(long long i, long long k, long long counter) {
  if (i > 7 || k > 7 || k < 0 || i < 0 || done) return;
  if (i == y2 && k == x2 && counter % 2 == 0) {
    done = 1;
    return;
  }
  arrbool[i][k] = 1;
  for (int h = 0; h < 4; h++) {
    if (i + arry[h] >= 0 && k + arrx[h] >= 0 &&
        arrbool[i + arry[h]][k + arrx[h]] == 0)
      arrive(i + arry[h], k + arrx[h], counter + 1);
  }
}
int main() {
  cin.tie(0);
  std::ios::sync_with_stdio(false);
  cin >> n;
  vector<string> out;
  for (int i = 0; i < n; i++) {
    long long counter = 0;
    done = 0;
    memset(arrbool, 0, 100);
    for (int k = 0; k < 8; k++)
      for (int h = 0; h < 8; h++) {
        cin >> arr[k][h];
        if (arr[k][h] == 'K' && counter == 0) {
          x11 = h;
          y11 = k;
          counter++;
        } else if (arr[k][h] == 'K') {
          x2 = h;
          y2 = k;
        }
      }
    arrive(y11, x11, 0);
    if (done) {
      out.push_back("YES");
    } else
      out.push_back("NO");
  }
  for (int i = 0; i < out.size(); i++) cout << out[i] << endl;
  return 0;
}
