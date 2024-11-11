#include <bits/stdc++.h>
using namespace std;
int n;
map<int, int> C;
int largest;
int a, b;
int main() {
  largest = -1;
  scanf("%d", &n);
  for (int i = 0; i < (n); ++i) {
    scanf("%d%d", &a, &b);
    C[a] = b;
    largest = max(largest, a);
  }
  int m = 0;
  long long c = 1;
  for (int i = 0; i < (20); ++i) {
    while ((C[largest - i] > c)) {
      c *= 4;
      m++;
    }
    if (c < 100000000000000LL) c *= 4;
  }
  cout << largest + m << endl;
}
