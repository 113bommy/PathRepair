#include <bits/stdc++.h>
using namespace std;
int main() {
  long long n = 0;
  cin >> n;
  vector<long long> vpl;
  for (int i = 0; i < n; i++) {
    string tempx;
    cin >> tempx;
    string hour = tempx.substr(0, 2);
    string minutes = tempx.substr(3);
    vpl.push_back(100 * atoi(hour.c_str()) + atoi(minutes.c_str()));
  }
  sort(vpl.begin(), vpl.end());
  if (vpl.size() == 1) {
    cout << "23:59" << endl;
  } else {
    vector<long long> diff;
    for (int i = 0; i < vpl.size() - 1; i++) {
      long long m1 = vpl[i] % 100;
      long long h1 = (vpl[i] - vpl[i] % 100) / 100;
      long long m2 = vpl[i + 1] % 100;
      long long h2 = (vpl[i + 1] - vpl[i + 1] % 100) / 100;
      diff.push_back(abs(m1 + 60 * h1 - m2 - 60 * h2) - 1);
    }
    long long m1 = vpl[0] % 100;
    long long h1 = (vpl[0] - vpl[0] % 100) / 100;
    long long m2 = vpl[vpl.size() - 1] % 100;
    long long h2 = (vpl[vpl.size() - 1] - vpl[vpl.size() - 1] % 100) / 100;
    diff.push_back(abs(m1 + 60 * (h1 + 24) - m2 - 60 * h2));
    sort(diff.begin(), diff.end());
    long long temp = diff[diff.size() - 1];
    long long res_m = temp % 60;
    long long res_h = (temp - temp % 60) / 60;
    if (res_h < 10) {
      cout << "0" << res_h << ":";
    } else {
      cout << res_h << ":";
    }
    if (res_m < 10) {
      cout << "0" << res_m << endl;
    } else {
      cout << res_m << endl;
    }
  }
  return 0;
}
