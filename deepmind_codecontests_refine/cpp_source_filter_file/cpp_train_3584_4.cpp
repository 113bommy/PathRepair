#include <bits/stdc++.h>
using namespace std;
int n;
int main() {
  cin >> n;
  int N = n / 2;
  if (n > 5) {
    for (int i = 1; i <= N; i++) cout << i << " " << i + N << " 1" << endl;
    for (int i = 1; i + N < n; i++)
      cout << i + N << " " << i + N + 1 << " " << 2 * N - 1 << endl;
    for (int i = 1; i < N; i++) cout << i << " " << i + 1 << endl;
    cout << "1 3" << endl;
  }
  if (n == 5) printf("1 2 3\n1 3 3\n2 4 2\n4 5 1\n3 4\n3 5\n");
}
