#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int ar[N + 1];
  for (int i = 0; i < N; i++) cin >> ar[i];
  int l = 0, r = 0;
  bool ok = true;
  for (int i = 1; i < N; i++) {
    if (!ok && ar[i] < ar[i - 1]) {
      cout << "0 0" << endl;
      return 0;
    }
    if (ar[i] < ar[i - 1]) {
      ok = false;
      l = i - 1;
      while (i < N && ar[i] <= ar[i - 1]) i++;
      r = i - 1;
    }
  }
  if ((l && ar[r] < ar[l - 1]) || (r != N - 1 && ar[l] > ar[r + 1]))
    cout << "0 0\n";
  else
    cout << l + 1 << " " << r + 1 << "\n";
  return 0;
}
