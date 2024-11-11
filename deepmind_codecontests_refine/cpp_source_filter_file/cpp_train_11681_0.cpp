#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e5 + 5;
long long ask1(int a, int b, int c) {
  cout << "1 " << a << " " << b << " " << c << '\n';
  int res;
  cin >> res;
  return res;
}
int ask2(int a, int b, int c) {
  cout << "2 " << a << " " << b << " " << c << '\n';
  int res;
  cin >> res;
  return res;
}
long long S2[maxn];
int main() {
  int n;
  cin >> n;
  vector<int> left, right;
  for (int i = 3; i <= n; i++) {
    int res = ask2(1, 2, i);
    if (res == 1) {
      left.push_back(i);
    } else {
      right.push_back(i);
    }
  }
  vector<int> answ, answ1;
  if (left.size() > 1) {
    int idx = 0;
    for (int i = 0; i < left.size(); i++) {
      S2[left[i]] = ask1(1, 2, left[i]);
      if (S2[left[i]] > S2[idx]) {
        idx = left[i];
      }
    }
    vector<int> left1, right1;
    for (int i = 0; i < left.size(); i++) {
      if (left[i] == idx) continue;
      if (ask2(1, idx, left[i]) == 1)
        left1.push_back(left[i]);
      else
        right1.push_back(left[i]);
    }
    sort(left1.begin(), left1.end(),
         [&](int a, int b) { return S2[a] > S2[b]; });
    sort(right1.begin(), right1.end(),
         [&](int a, int b) { return S2[a] < S2[b]; });
    for (int i = 0; i < right1.size(); i++) {
      answ.push_back(right1[i]);
    }
    answ.push_back(idx);
    for (int i = 0; i < left1.size(); i++) {
      answ.push_back(left1[i]);
    }
  } else {
    answ = left;
  }
  if (right.size() > 1) {
    int idx = 0;
    for (int i = 0; i < right.size(); i++) {
      S2[right[i]] = ask1(1, 2, right[i]);
      if (S2[right[i]] > S2[idx]) {
        idx = right[i];
      }
    }
    vector<int> left1, right1;
    for (int i = 0; i < right.size(); i++) {
      if (right[i] == idx) continue;
      if (ask2(1, idx, right[i]) == 1)
        left1.push_back(right[i]);
      else
        right1.push_back(right[i]);
    }
    sort(left1.begin(), left1.end(),
         [&](int a, int b) { return S2[a] > S2[b]; });
    sort(right1.begin(), right1.end(),
         [&](int a, int b) { return S2[a] < S2[b]; });
    for (int i = 0; i < right1.size(); i++) {
      answ1.push_back(right1[i]);
    }
    answ1.push_back(idx);
    for (int i = 0; i < left1.size(); i++) {
      answ1.push_back(left1[i]);
    }
  } else {
    answ1 = right;
  }
  cout << "0 1 ";
  for (int i = 0; i < answ1.size(); i++) {
    cout << answ1[i] << ' ';
  }
  cout << "2" << ' ';
  for (int i = 0; i < answ.size(); i++) {
    cout << answ[i] << ' ';
  }
  return 0;
}
