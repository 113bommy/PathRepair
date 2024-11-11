#include <bits/stdc++.h>
using namespace std;
bool checkIt(vector<pair<long double, int> > vec) {
  sort(vec.begin(), vec.end());
  long long int tot = 0;
  for (long long int i = 0; i < vec.size(); i++) {
    if (vec[i].second == 1) {
      tot++;
    } else {
      tot--;
    }
    if (tot > 1) {
      return true;
    }
  }
  return false;
}
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n, l;
    cin >> n >> l;
    long long int arr[n + 2];
    for (long long int i = 1; i <= n; i++) {
      cin >> arr[i];
    }
    arr[0] = 0;
    arr[n + 1] = l;
    long double start[n + 2];
    long double end[n + 2];
    long long int startV[n + 2];
    long long int endV[n + 2];
    long long int prevV = 1;
    start[0] = 0;
    startV[0] = 1;
    endV[n + 1] = 1;
    long double tym, dist;
    for (long long int i = 1; i <= (n + 1); i++) {
      dist = arr[i] - arr[i - 1];
      tym = (double)dist / (double)prevV;
      start[i] = start[i - 1] + tym;
      prevV++;
      startV[i] = prevV;
    }
    prevV = 1;
    end[n + 1] = 0;
    for (long long int i = (n); i >= 0; i--) {
      dist = abs(arr[i] - arr[i + 1]);
      tym = (double)dist / (double)prevV;
      end[i] = end[i + 1] + tym;
      prevV++;
      endV[i] = prevV;
    }
    long double aa, bb, cc, dd;
    long double v1, v2, diff1, ans, j1, toti, t1;
    for (long long int i = 1; i <= (n + 1); i++) {
      aa = start[i - 1];
      bb = start[i];
      cc = end[i];
      dd = end[i - 1];
      vector<pair<long double, int> > vc;
      vc.push_back(make_pair(aa, 1));
      vc.push_back(make_pair(bb, 2));
      vc.push_back(make_pair(cc, 1));
      vc.push_back(make_pair(dd, 2));
      bool bg = checkIt(vc);
      if (bg) {
        dist = (arr[i] - arr[i - 1]);
        v1 = startV[i - 1];
        v2 = endV[i];
        diff1 = (start[i - 1] - end[i]);
        diff1 = (diff1 * v1 * v2);
        diff1 = diff1 - (v1 * dist);
        toti = v1 + v2;
        j1 = diff1 / (toti);
        ans = abs(j1);
        t1 = ans / v1;
        t1 = t1 + start[i - 1];
        cout << fixed << setprecision(8) << t1 << endl;
        break;
      }
    }
  }
}
