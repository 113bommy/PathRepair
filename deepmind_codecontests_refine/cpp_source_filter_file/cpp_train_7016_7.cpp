#include <bits/stdc++.h>
using namespace std;
int main() {
  set<long long> x;
  set<long long> y;
  long long pts[8][2];
  for (long long i = 0; i < 8; i++) {
    long long temp;
    cin >> temp;
    pts[i][0] = temp;
    x.insert(temp);
    cin >> temp;
    pts[i][1] = temp;
    y.insert(temp);
    for (long long j = 0; j < i; j++) {
      if (pts[i][0] == pts[j][0] && pts[i][1] == pts[i][1]) {
        cout << "ugly" << endl;
        return 0;
      }
    }
  }
  if (x.size() != 3 || y.size() != 3) {
    cout << "ugly" << endl;
    return 0;
  }
  long long tx[3], ty[3];
  set<long long>::iterator it = x.begin();
  set<long long>::iterator ite = y.begin();
  for (long long i = 0; i < 3; i++) {
    tx[i] = *it;
    it++;
    ty[i] = *ite;
    ite++;
  }
  for (long long i = 0; i < 8; i++) {
    if (pts[i][0] == tx[1] && pts[i][1] == ty[1]) {
      cout << "ugly" << endl;
      return 0;
    }
  }
  cout << "respectable" << endl;
}
