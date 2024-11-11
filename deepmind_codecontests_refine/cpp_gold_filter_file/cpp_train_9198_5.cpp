#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> b(N, 0);
  for (int i = 0; i < N; i++) {
    cin >> b[i];
  }
  map<long long, long long> d;
  d[b[0]] = 1;
  d[0] = 0;
  cout << 1 << " " << b[0] << endl;
  for (int s = 1; s < N && d.size() <= K; s++) {
    map<long long, long long>::iterator it = d.begin(), itEnd = d.end();
    for (; it != itEnd; ++it) {
      if (d.find(it->first + b[s]) == d.end()) {
        if (it->second & (1LL << s)) continue;
        int count = 0;
        for (int i = 0; i < N; i++) {
          if (it->second & (1LL << i)) {
            count++;
          }
        }
        cout << count + 1 << " ";
        for (int i = 0; i < N; i++) {
          if (it->second & (1LL << i)) {
            cout << b[i] << " ";
          }
        }
        cout << b[s] << endl;
        d[it->first + b[s]] = it->second | (1LL << s);
        if (d.size() == K + 1) break;
      }
    }
  }
  return 0;
}
