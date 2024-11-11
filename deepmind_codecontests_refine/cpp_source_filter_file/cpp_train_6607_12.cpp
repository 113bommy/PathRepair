#include <bits/stdc++.h>
using namespace std;
int N;
int main() {
  cin >> N;
  if (N % 2 != 0) {
    cout << 1 << " ";
    for (int i = 2; i <= N; i += 2) printf(" %d %d", i + 1, i);
  } else
    for (int i = 1; i <= N; i += 2) printf("%d %d", i + 1, i);
}
