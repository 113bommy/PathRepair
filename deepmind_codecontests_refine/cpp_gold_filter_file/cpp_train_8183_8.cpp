#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
  srand(time(NULL));
  ;
  long long n;
  cin >> n;
  cout << 1 << " ";
  long long cnt = 1;
  long long last = n;
  map<long long, bool> visited;
  for (long long i = 0; i < n; i++) {
    long long temp = 0;
    cin >> temp;
    visited[temp] = true;
    cnt++;
    while (visited[last] == true) {
      last--;
      cnt--;
    }
    cout << max(cnt, (long long)1) << " ";
  }
  return 0;
}
