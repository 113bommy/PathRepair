#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    v.push_back(a);
  }
  if (n == 0) {
    cout << "YES" << endl;
    cout << 1 << endl;
    cout << 1 << endl;
    cout << 3 << endl;
    cout << 3 << endl;
    return 0;
  }
  if (n == 1) {
    int val1 = v[0];
    int val2 = v[0] + 1;
    int val3 = val1 * 4 - val2;
    int val4 = val1 * 3;
    cout << "YES" << endl;
    cout << val2 << endl;
    cout << val3 << endl;
    cout << val4 << endl;
  } else if (n == 4) {
    sort(v.begin(), v.end());
    if (v[0] * 3 == v[3] && v[1] + v[2] == v[0] * 4)
      cout << "YES" << endl;
    else
      cout << "NO" << endl;
  } else if (n == 2) {
    int val1 = v[0];
    int val2 = v[1];
    if (val1 > val2) swap(val1, val2);
    int val4 = val1 * 3;
    int val3 = val1 * 4 - val2;
    int mn = min(val2, val3);
    int mx = max(val2, val3);
    if (mn >= val1 && mx <= val4) {
      cout << "YES" << endl;
      cout << val3 << endl;
      cout << val4 << endl;
      return 0;
    }
    if (val2 % 3 == 0 && val2 / 3 == val1) {
      int now1 = val1 + 1;
      int now2 = val1 * 4 - now1;
      mn = min(now1, now2);
      mx = max(now1, now2);
      if (mn >= val1 && mx <= val2) {
        cout << "YES" << endl;
        cout << now1 << endl;
        cout << now2 << endl;
        return 0;
      }
    }
    if (val2 % 3 == 0) {
      int now1 = val2 / 3;
      int temp = now1 * 4;
      int now2 = temp - val1;
      mn = min(val1, now2);
      mx = max(val1, now2);
      if (mn >= now1 && mx <= val2) {
        cout << "YES" << endl;
        cout << now1 << endl;
        cout << now2 << endl;
        return 0;
      }
    }
    if ((val1 + val2) % 4 == 0) {
      int now1 = (val1 + val2) / 4;
      int now4 = now1 * 3;
      mn = min(val2, val1);
      mx = max(val2, val1);
      if (mn >= now1 && mx <= now4) {
        cout << "YES" << endl;
        cout << now1 << endl;
        cout << now4 << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  } else if (n == 3) {
    sort(v.begin(), v.end());
    if ((v[1] + v[2]) % 4 == 0 && ((v[1] + v[2]) / 4) == v[0] &&
        v[0] * 3 >= v[2]) {
      cout << "YES" << endl;
      cout << v[0] * 3 << endl;
      return 0;
    }
    if (v[2] % 3 == 0 && v[2] / 3 == v[0]) {
      int now2 = v[0] * 4 - v[1];
      int mn = min(now2, v[1]);
      int mx = max(now2, v[1]);
      if (mn >= v[0] && mx <= v[2]) {
        cout << "YES" << endl;
        cout << now2 << endl;
        return 0;
      }
    }
    if (v[3] % 3 == 0) {
      int now1 = v[3] / 3;
      if (v[0] + v[1] == now1 * 4) {
        cout << "YES" << endl;
        cout << now1 << endl;
        return 0;
      }
    }
    cout << "NO" << endl;
  }
}
