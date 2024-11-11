#include <bits/stdc++.h>
using namespace std;
const int infK = 0x3f3f3f3f;
const long long infLLK = 0x3f3f3f3f3f3f3f3f;
int main() {
  int i, j, k;
  int num, len;
  priority_queue<int> pq;
  cin >> num >> len;
  for (i = 0; i < num; i++) {
    int temp;
    cin >> temp;
    if (len % temp == 0) {
      pq.push(temp);
    }
  }
  int a = pq.top();
  cout << len / a << endl;
  return 0;
}
