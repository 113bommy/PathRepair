#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  while (cin >> N) {
    int p[N + 6];
    for (int i = 1; i <= N; i++) p[i] = i;
    for (int i = 2; i <= N; i += 2) p[i] = 2;
    for (int i = 3; i * i <= N; i += 2)
      if (p[i] == i)
        for (int j = i; j <= N; j += i)
          if (p[j] == j) p[j] = i;
    int n = N;
    int sum = n;
    while (n != 1) {
      n /= p[n];
      sum += n;
    }
    cout << sum << endl;
  }
  return 0;
}
