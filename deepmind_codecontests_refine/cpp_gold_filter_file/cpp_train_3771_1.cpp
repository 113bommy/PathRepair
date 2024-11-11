#include <bits/stdc++.h>
using namespace std;
struct node {
  char ch;
  int val;
  int idx;
  node(char ch = 'a', int val = -1, int idx = 0) : ch(ch), val(val), idx(idx) {}
};
void swap(node& a, node& b) {
  node temp(a.ch, a.val, a.idx);
  a = b;
  b = temp;
}
void disp(vector<node>& arr) {
  for (auto e : arr) cout << e.ch << "\t";
  cout << "\n";
  for (auto e : arr) cout << e.val << "\t";
  cout << "\n";
  for (auto e : arr) cout << e.idx << "\t";
  cout << "\n";
}
int main() {
  {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
  };
  long long n;
  cin >> n;
  string str;
  cin >> str;
  vector<long long> res(n, -1);
  vector<node> arr(n);
  for (int i = 0; i < n; i++) {
    arr[i].ch = str[i];
    arr[i].idx = i;
  }
  for (int i = 0; i < n; i++) {
    bool isZero = 0, isOne = 0;
    char smallestChar = arr[i].ch;
    int idx = i;
    for (int j = i; j < n; j++) {
      if (int(smallestChar) > int(arr[j].ch)) {
        smallestChar = arr[j].ch;
        idx = j;
      }
    }
    for (int j = i; j < idx; j++) {
      if (arr[j].val == 0)
        isZero = 1;
      else if (arr[j].val == 1)
        isOne = 1;
    }
    if (isZero and isOne) {
      cout << "NO\n";
      return 0;
    } else if (isZero) {
      if (arr[idx].val == 0) {
        cout << "NO\n";
        return 0;
      } else {
        arr[idx].val = 1;
        for (int j = i; j < idx; j++) arr[j].val = 0;
        for (int j = idx; j > i; j--) swap(arr[j], arr[j - 1]);
      }
    } else if (isOne) {
      if (arr[idx].val == 1) {
        cout << "NO\n";
        return 0;
      } else {
        arr[idx].val = 0;
        for (int j = i; j < idx; j++) arr[j].val = 1;
        for (int j = idx; j > i; j--) swap(arr[j], arr[j - 1]);
      }
    } else {
      if (arr[idx].val == 1) {
        for (int j = i; j < idx; j++) arr[j].val = 0;
        for (int j = idx; j > i; j--) swap(arr[j], arr[j - 1]);
      } else if (arr[idx].val == 0) {
        for (int j = i; j < idx; j++) arr[j].val = 1;
        for (int j = idx; j > i; j--) swap(arr[j], arr[j - 1]);
      } else {
        arr[idx].val = 1;
        for (int j = i; j < idx; j++) arr[j].val = 0;
        for (int j = idx; j > i; j--) swap(arr[j], arr[j - 1]);
      }
    }
  }
  cout << "YES\n";
  for (auto e : arr) res[e.idx] = e.val;
  for (auto e : res) cout << e;
  cout << "\n";
  return 0;
}
