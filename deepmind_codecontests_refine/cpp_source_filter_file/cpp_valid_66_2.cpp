#include <bits/stdc++.h>
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int k;
    cin >> k;
    vector<int> temp;
    int count = 0;
    int num = 1;
    while (true) {
      if (count == k) break;
      if (num % 10 == 3 || num / 3 == 0)
        num++;
      else {
        temp.push_back(num);
        count++;
        num++;
      }
    }
    cout << temp[temp.size() - 1] << endl;
  }
  return 0;
}
