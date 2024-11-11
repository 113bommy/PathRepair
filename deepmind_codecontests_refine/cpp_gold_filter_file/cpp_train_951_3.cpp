#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 7;
int a[N];
int main() {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++) cin >> a[i];
  int l = 0, r = n - 1;
  vector<int> ans;
  vector<char> ans2;
  if (a[l] < a[r]) {
    ans.push_back(a[l]);
    l++;
    ans2.push_back('L');
  } else if (a[r] < a[l]) {
    ans.push_back(a[r]);
    r--;
    ans2.push_back('R');
  } else {
    int t1 = 1, t2 = 1;
    for (int i = 1; i < n; i++) {
      if (a[i] > a[i - 1])
        t1++;
      else
        break;
    }
    for (int i = n - 1; i >= 0; i--)
      if (a[i - 1] > a[i])
        t2++;
      else
        break;
    if (t1 >= t2) {
      cout << t1 << endl;
      for (int i = 0; i < t1; i++) cout << 'L';
      cout << endl;
      return 0;
    } else {
      cout << t2 << endl;
      for (int i = 0; i < t2; i++) cout << 'R';
      cout << endl;
      return 0;
    }
  }
  while (ans.size() < n) {
    if ((a[l] > ans[ans.size() - 1]) && (a[r] > ans[ans.size() - 1])) {
      if (a[l] < a[r]) {
        ans.push_back(a[l]);
        l++;
        ans2.push_back('L');
      } else if (a[r] < a[l]) {
        ans.push_back(a[r]);
        r--;
        ans2.push_back('R');
      } else {
        int t1 = 1, t2 = 1;
        for (int i = l; i < n; i++)
          if (a[i + 1] > a[i])
            t1++;
          else
            break;
        for (int i = r; i >= 0; i--)
          if (a[i - 1] > a[i])
            t2++;
          else
            break;
        if (t1 >= t2) {
          cout << ans.size() + t1 << endl;
          for (int i = 0; i < ans2.size(); i++) cout << ans2[i];
          for (int i = 0; i < t1; i++) cout << 'L';
          cout << endl;
          return 0;
        } else {
          cout << ans.size() + t2 << endl;
          for (int i = 0; i < ans2.size(); i++) cout << ans2[i];
          for (int i = 0; i < t2; i++) cout << 'R';
          cout << endl;
          return 0;
        }
      }
    } else if ((a[l] > ans[ans.size() - 1]) && (a[r] <= ans[ans.size() - 1])) {
      ans.push_back(a[l]);
      l++;
      ans2.push_back('L');
    } else if ((a[l] <= ans[ans.size() - 1]) && (a[r] > ans[ans.size() - 1])) {
      ans.push_back(a[r]);
      r--;
      ans2.push_back('R');
    } else
      break;
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans2.size(); i++) cout << ans2[i];
  cout << endl;
}
