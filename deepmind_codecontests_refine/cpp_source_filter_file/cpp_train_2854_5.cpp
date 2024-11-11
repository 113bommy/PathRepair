#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  int array[N];
  for (int i = 0; i < N; i++) {
    cin >> array[i];
  }
  int ans = 2, get = 0;
  if (N < 2) get = 2;
  for (int i = 2; i < N; i++) {
    if (array[i] == array[i - 1] + array[i - 2]) {
      ans++;
    } else {
      ans = 2;
    }
    get = max(get, ans);
  }
  cout << get << endl;
  return 0;
}
