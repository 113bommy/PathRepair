#include <bits/stdc++.h>
using namespace std;
int main() {
  string mname;
  string tmp, name1, name2, action;
  int n, i, p;
  cin >> mname;
  cin >> n;
  map<string, int> arr;
  cin.get();
  for (i = 0; i < n; ++i) {
    getline(cin, tmp, '\n');
    p = 0;
    p = tmp.find(' ', p);
    name1 = tmp;
    name1.erase(p, name1.length());
    tmp.erase(0, p + 1);
    p = 0;
    p = tmp.find(' ', p);
    action = tmp;
    action.erase(p, action.length());
    tmp.erase(0, p + 1);
    if (action == "posted" || action == "commented") {
      tmp.erase(0, 3);
    };
    p = 0;
    p = tmp.find('\'', p);
    name2 = tmp;
    name2.erase(p, name2.length());
    if (name1 == mname || name2 == mname) {
      if (action == "posted") {
        if (name1 == mname) {
          arr.insert(pair<string, int>(name2, 0));
          arr[name2] += 15;
        } else {
          arr.insert(pair<string, int>(name1, 0));
          arr[name1] += 15;
        }
      }
      if (action == "commented") {
        if (name1 == mname) {
          arr.insert(pair<string, int>(name2, 0));
          arr[name2] += 10;
        } else {
          arr.insert(pair<string, int>(name1, 0));
          arr[name1] += 10;
        }
      }
      if (action == "likes") {
        if (name1 == mname) {
          arr.insert(pair<string, int>(name2, 0));
          arr[name2] += 5;
        } else {
          arr.insert(pair<string, int>(name1, 0));
          arr[name1] += 5;
        }
      }
    } else {
      arr.insert(pair<string, int>(name1, 0));
      arr.insert(pair<string, int>(name2, 0));
    }
  }
  map<string, int>::iterator it;
  string str[100];
  int l = 0, j;
  for (it = arr.begin(); it != arr.end(); ++it) {
    str[l++] = it->first;
  }
  for (i = 0; i < l - 1; ++i) {
    for (j = i + 1; j < l; ++j) {
      if (arr[str[i]] < arr[str[j]]) {
        swap(str[i], str[j]);
      } else if (arr[str[i]] == arr[str[j]] && str[i].compare(str[j]) < 0) {
        swap(str[i], str[j]);
      }
    }
  }
  for (i = 0; i < l; ++i) {
    cout << str[i] << endl;
  }
  return 0;
}
