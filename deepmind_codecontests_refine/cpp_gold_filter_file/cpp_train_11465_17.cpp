#include <bits/stdc++.h>
using namespace std;
long long inp;
int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.precision(20);
  long long t;
  cin >> t;
  vector<double> sb, sa;
  double d;
  for (int i = (0); i < (t); i++) {
    cin >> d;
    if (d == 0) {
      sa.push_back(0);
      sb.push_back(0);
    } else if (d < 4) {
      sa.push_back(-1);
      sb.push_back(-1);
    } else {
      double b = (d + sqrt((double)d * d - (double)4 * d)) / 2;
      sb.push_back(b);
      sa.push_back(b / (b - 1));
    }
  }
  for (int i = (0); i < (t); i++) {
    if (sa[i] == -1) {
      cout << "N" << endl;
    } else {
      cout << "Y " << sb[i] << " " << sa[i] << endl;
    }
  }
  return 0;
}
