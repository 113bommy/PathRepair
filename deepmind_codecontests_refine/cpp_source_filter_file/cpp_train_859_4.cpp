#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  cin >> n;
  vector<int> v(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  vector<vector<int> > res;
  if (n == 1) {
    cout << 0 << endl;
    return 0;
  } else {
    int st = -1, end = -1;
    for (int i = 0; i < n; i++) {
      if (v[i] == 1) {
        st = i;
        end = i;
        break;
      }
    }
    int idx = -1;
    for (int i = 0; i < n; i++) {
      if (v[i] == 2) {
        idx = i;
        break;
      }
    }
    if (idx > st) {
      vector<int> temp;
      if (st) temp.push_back(st);
      temp.push_back(st + 1);
      temp.push_back(idx + 1);
      if (idx < n - 1) temp.push_back(n);
      int k = 0;
      vector<int> a(n);
      for (int j = temp.size() - 1; j >= 0; j--) {
        int prev = 0;
        if (j) prev = temp[j - 1];
        for (int x = prev; x < temp[j]; x++) a[k++] = v[x];
      }
      v = a;
      res.push_back(temp);
    } else {
      vector<int> temp;
      if (idx) temp.push_back(idx);
      temp.push_back(idx + 1);
      temp.push_back(st + 1);
      if (st < n - 1) temp.push_back(n);
      int k = 0;
      vector<int> a(n);
      for (int j = temp.size() - 1; j >= 0; j--) {
        int prev = 0;
        if (j) prev = temp[j - 1];
        for (int x = prev; x < temp[j]; x++) a[k++] = v[x];
      }
      v = a;
      res.push_back(temp);
    }
    for (int i = 0; i < n; i++) {
      if (v[i] == 2)
        end = i;
      else if (v[i] == 1)
        st = i;
    }
    for (int i = 3; i <= n; i++) {
      for (int k = 0; k < n; k++) {
        if (v[k] == i) {
          idx = k;
          break;
        }
      }
      if ((idx > st && end < st) || (idx < st && st < end)) {
        vector<int> temp;
        if (idx > st) {
          if (end) temp.push_back(end);
          temp.push_back(st + 1);
          temp.push_back(idx + 1);
          if (idx < n - 1) temp.push_back(n);
        } else {
          if (idx) temp.push_back(idx);
          temp.push_back(st);
          temp.push_back(end + 1);
          if (end < n - 1) temp.push_back(n);
        }
        int k = 0;
        vector<int> a(n);
        for (int j = temp.size() - 1; j >= 0; j--) {
          int prev = 0;
          if (j) prev = temp[j - 1];
          for (int x = prev; x < temp[j]; x++) a[k++] = v[x];
        }
        v = a;
        res.push_back(temp);
      } else {
        vector<int> temp;
        if (idx > st) {
          if (st) temp.push_back(st);
          for (int j = st + 1; j <= end; j++) temp.push_back(j);
          temp.push_back(end + 1);
          temp.push_back(idx + 1);
          if (idx < n - 1) temp.push_back(n);
        } else {
          if (idx) temp.push_back(idx);
          for (int j = end; j <= st; j++) temp.push_back(j);
          temp.push_back(st + 1);
          if (st < n - 1) temp.push_back(n);
        }
        int k = 0;
        vector<int> a(n);
        for (int j = temp.size() - 1; j >= 0; j--) {
          int prev = 0;
          if (j) prev = temp[j - 1];
          for (int x = prev; x < temp[j]; x++) a[k++] = v[x];
        }
        v = a;
        res.push_back(temp);
      }
      for (int j = 0; j < n; j++) {
        if (v[j] == i)
          end = j;
        else if (v[j] == 1)
          st = j;
      }
    }
  }
  if (v[1] < v[0]) {
    vector<int> temp;
    for (int i = 1; i < n; i++) temp.push_back(i);
    res.push_back(temp);
    sort(v.begin(), v.end());
  }
  cout << res.size() << endl;
  for (int i = 0; i < res.size(); i++) {
    cout << res[i].size() << " " << res[i][0] << " ";
    for (int j = 1; j < res[i].size(); j++)
      cout << res[i][j] - res[i][j - 1] << " ";
    cout << endl;
  }
  return 0;
}
