#include <bits/stdc++.h>
using namespace std;
const int MAX_N = 2e5;
int arr[MAX_N];
int main(void) {
  ios_base::sync_with_stdio(false), cin.tie(NULL);
  int N;
  cin >> N;
  for (int i = 0; i < N; i++) cin >> arr[i];
  int f, x;
  cin >> f >> x;
  long long res = 0;
  for (int i = 0; i < N; i++) {
    if (arr[i] > f) {
      res += (long long)x * ((arr[i] + x) / (x + f));
    }
  }
  cout << res << endl;
}
