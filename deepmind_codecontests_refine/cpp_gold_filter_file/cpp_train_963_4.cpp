#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, un, maximum;
  cin >> n;
  while (n--) {
    vector<int> v;
    cin >> un;
    int ele, non_repeated = 0;
    int missing;
    for (int i = 0; i < un; i++) {
      cin >> ele;
      v.push_back(ele);
    }
    int flag = 1;
    sort(v.begin(), v.end());
    maximum = v[un - 1];
    if (v[0] != 0) {
      cout << non_repeated << "\n";
      continue;
    }
    non_repeated = v[0];
    int i;
    for (i = 1; i < v.size(); i++) {
      if (v[i] == non_repeated) {
        flag = 0;
        continue;
      }
      if (v[i] != non_repeated) {
        if (flag == 1) break;
        if (flag == 0) {
          non_repeated = non_repeated + 1;
          flag = 1;
        }
      }
    }
    if (non_repeated == maximum && v[un - 2] == non_repeated && v.size() >= 2)
      non_repeated++;
    missing = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] == missing)
        continue;
      else if (v[i] == missing + 1) {
        missing = missing + 1;
      } else {
        missing = missing + 1;
        break;
      }
    }
    if (maximum == missing) missing++;
    cout << (non_repeated + missing) << "\n";
  }
  return 0;
}
