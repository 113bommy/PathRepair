#include <bits/stdc++.h>
using namespace std;
deque<long long> deq;
long long n, m, i, j, k, Max = 0, temp, ci = 0, a, b, aa[200006], bb[200006],
                         arr[200005];
int main() {
  ios::sync_with_stdio(false);
  cin >> n >> m;
  for (i = 1; i <= n; i++) {
    cin >> temp;
    deq.push_back(temp);
    Max = max(Max, temp);
  }
  while (1) {
    a = deq.front();
    deq.pop_front();
    b = deq.front();
    deq.pop_front();
    if (a == Max) {
      deq.push_front(b);
      deq.push_front(a);
      break;
    } else {
      ci++;
      aa[ci] = a;
      bb[ci] = b;
      if (a > b) {
        deq.push_front(a);
        deq.push_back(b);
      } else {
        deq.push_front(b);
        deq.push_back(a);
      }
    }
  }
  for (i = 1; i <= n; i++) {
    arr[i] = deq.front();
    deq.pop_front();
  }
  for (i = 1; i <= m; i++) {
    cin >> temp;
    if (temp < ci) {
      cout << aa[temp] << " " << bb[temp] << endl;
    } else {
      temp -= ci;
      temp %= (n - 1);
      if (temp != 0) {
        cout << Max << " " << arr[temp + 1] << endl;
      } else {
        cout << Max << " " << arr[n] << endl;
      }
    }
  }
  return 0;
}
