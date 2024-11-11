#include <bits/stdc++.h>
const int INF = 1e9 + 1;
const int MOD = 1e9 + 7;
const int N = 1e6 + 1;
using namespace std;
int main() {
  int n, x, y, z;
  cin >> n;
  list<int> arr;
  for (int i = 0; i < n; i++) {
    cin >> x;
    arr.push_back(x);
  }
  string str = "";
  int current = 0;
  while (arr.size()) {
    x = *arr.begin();
    y = *arr.rbegin();
    if (x <= current && y <= current) {
      break;
    }
    if (x < y && x > current) {
      str += 'L';
      current = x;
      arr.pop_front();
    } else if (y < x && y > current) {
      str += 'R';
      current = y;
      arr.pop_back();
    } else if (x == y && x > current) {
      int a = 1, b = 1;
      list<int>::iterator it;
      it = arr.begin();
      it++;
      while (it != arr.end()) {
        if (*it > x) {
          a++;
          x = *it;
          it++;
        } else {
          break;
        }
      }
      list<int>::reverse_iterator itt;
      itt = arr.rbegin();
      itt++;
      while (b < arr.size()) {
        if (*itt > y) {
          b++;
          y = *itt;
          itt++;
        } else {
          break;
        }
      }
      if (a > b) {
        while (a--) {
          str += 'L';
        }
      } else {
        while (b--) {
          str += 'R';
        }
      }
      break;
    } else if (y > current) {
      str += 'R';
      current = y;
      arr.pop_back();
    } else {
      str += 'L';
      current = x;
      arr.pop_front();
    }
  }
  cout << str.size() << endl;
  cout << str << endl;
}
