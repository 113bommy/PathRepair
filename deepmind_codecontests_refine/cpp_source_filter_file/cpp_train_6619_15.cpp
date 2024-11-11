#include <bits/stdc++.h>
using namespace std;
int main(int argc, const char* argv[]) {
  int qty, sock, ans, curSize;
  set<int> s;
  cin >> qty;
  for (int i = 0; i < 2 * qty; i++) {
    int sizeB = s.size();
    cin >> sock;
    s.insert(sock);
    curSize = s.size();
    if (sizeB == curSize) {
      s.erase(sock);
    }
    ans = max(ans, curSize);
  }
  cout << ans;
  return 0;
}
