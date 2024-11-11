#include <bits/stdc++.h>
using namespace std;
bool notprime(int k) {
  if (k == 0 || k == 1 || k == 2) {
    return false;
  }
  int t = int(sqrt(k)) + 1;
  for (int i = 2; i <= t; i++) {
    if (k % i == 0 && i != k) {
      return true;
    }
  }
  return false;
}
pair<bool, vector<int>> isit(int k, int accum, vector<int> v) {
  vector<int> blankvector(0);
  if (k > v.size()) {
    return {false, blankvector};
  }
  if (v.size() == k) {
    vector<int> answer;
    for (int i = 0; i < k; i++) {
      answer.push_back(i);
    }
    if (notprime(accum + accumulate(v.begin(), v.end(), 0))) {
      return {true, answer};
    } else {
      return {false, blankvector};
    }
  } else {
    int number = v[v.size() - 1];
    int position = int(v.size() - 1);
    v.pop_back();
    if (isit(k - 1, accum + number, v).first) {
      vector<int> answer = isit(k - 1, accum + number, v).second;
      answer.push_back(position);
      return {true, answer};
    }
    if (isit(k, accum, v).first) {
      return {true, isit(k, accum, v).second};
    } else {
      return {false, blankvector};
    }
  }
}
int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; i++) {
    int n, m;
    cin >> n >> m;
    vector<int> v(n);
    for (int i = 0; i < m; i++) {
      int a, b, c;
      cin >> a >> b >> c;
      v[b - 1]++;
    }
    for (int i = 0; i < n; i++) {
      if (v[i] == 0) {
        for (int j = 1; j <= n; j++) {
          if (j != i + 1) {
            cout << j << " " << i + 1 << endl;
          }
        }
        break;
      }
    }
  }
}
