#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  int photonumber = 0;
  vector<int> records;
  for (int i = 0; i <= 1000000; i++) records.push_back(0);
  long long maxx = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    records[x] += i;
    if (records[x] > maxx) {
      maxx = records[x];
      photonumber = x;
    }
  }
  cout << photonumber << endl;
  return 0;
}
