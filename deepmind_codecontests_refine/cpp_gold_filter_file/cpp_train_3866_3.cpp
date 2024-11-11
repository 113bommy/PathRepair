#include <bits/stdc++.h>
const double pi = 3.141592653589793238462643383279;
using namespace std;
long long GCD(long long a, long long b) {
  if (b == 0) return a;
  return GCD(b, a % b);
}
int arr[1000010];
int rev[1000010];
int main() {
  cin.tie(0);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(10);
  int n;
  cin >> n;
  string s;
  cin >> s;
  if (s[0] == ')' && s[s.size() - 1] == '(') {
    cout << 0 << endl;
    return 0;
  } else if (s[0] == ')') {
    arr[0]++;
    arr[1] += arr[0];
    bool f = true;
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == '(')
        arr[i]++;
      else
        arr[i]--;
      arr[i + 1] += arr[i];
      if (arr[i] < 0) f = false;
    }
    if (f && arr[s.size() - 1] == 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  } else if (s[s.size() - 1] == '(') {
    bool f = true;
    for (int i = 0; i < s.size() - 1; i++) {
      if (s[i] == '(')
        arr[i]++;
      else
        arr[i]--;
      arr[i + 1] += arr[i];
      if (arr[i] < 0) f = false;
    }
    arr[s.size() - 1]--;
    if (f && arr[s.size() - 1] == 0)
      cout << 1 << endl;
    else
      cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == '(') {
      arr[i]++;
    } else {
      arr[i]--;
    }
    arr[i + 1] += arr[i];
  }
  for (int i = s.size() - 1; i >= 0; i--) {
    if (s[i] == '(') {
      rev[i]++;
    } else {
      rev[i]--;
    }
    rev[i] += rev[i + 1];
  }
  if (arr[s.size() - 1] == 2) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (arr[i] < 0) {
        cout << 0 << endl;
        return 0;
      }
    }
    for (int i = s.size() - 1; i >= 0; i--) {
      if (arr[i] <= 1) break;
      if (s[i] == '(') ans++;
    }
    cout << ans << endl;
  } else if (arr[s.size() - 1] == -2) {
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
      if (arr[i] <= -3) {
        cout << 0 << endl;
        return 0;
      }
    }
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == ')') {
        ans++;
        if (arr[i] < 0) {
          break;
        }
      }
    }
    cout << ans << endl;
  } else {
    cout << 0 << endl;
  }
  return 0;
}
