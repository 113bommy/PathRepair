#include <bits/stdc++.h>
using namespace std;
using namespace std;
int main(int argc, char* argv[]) {
  long long c, h1, h2, w1, w2;
  cin >> c >> h1 >> h2 >> w1 >> w2;
  if (h1 * w1 < h2 * w1) {
    swap(h1, h2);
    swap(w1, w2);
  }
  long long n1 = c / w1;
  long long n2 = (c - n1 * w1) / w2;
  long long h = n1 * h1 + n2 * h2;
  int k = 0;
  while (true) {
    if (n1 < 0) break;
    n1 = (c - (n2 + 1) * w2) / w1;
    n2 = (c - n1 * w1) / w2;
    if (n1 < 0 || n2 < 0) break;
    long long newH = n1 * h1 + n2 * h2;
    if (k > 10000000) break;
    h = max(newH, h);
    if (n1 == 0) break;
    k++;
  }
  swap(h1, h2);
  swap(w1, w2);
  n1 = c / w1;
  n2 = (c - n1 * w1) / w2;
  h = max(h, n1 * h1 + n2 * h2);
  k = 0;
  while (true) {
    if (n1 < 0) break;
    n1 = (c - (n2 + 1) * w2) / w1;
    n2 = (c - n1 * w1) / w2;
    if (n1 < 0 || n2 < 0) break;
    long long newH = n1 * h1 + n2 * h2;
    if (k > 10000000) break;
    h = max(newH, h);
    if (n1 == 0) break;
    k++;
  }
  cout << h << endl;
  return 0;
}
