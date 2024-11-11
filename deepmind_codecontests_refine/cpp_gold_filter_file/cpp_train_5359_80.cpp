#include <bits/stdc++.h>
using namespace std;
int main() {
  int a, b;
  cin >> a >> b;
  int x;
  cin >> x;
  vector<int> boy;
  for (int i = 0; i < x; i++) {
    int temp;
    cin >> temp;
    boy.push_back(temp);
  }
  int y;
  cin >> y;
  vector<int> girl;
  for (int i = 0; i < y; i++) {
    int temp;
    cin >> temp;
    girl.push_back(temp);
  }
  if (boy.size() >= girl.size()) {
    for (int i = 0; i < boy.size(); i++) {
      for (int j = 0; j <= 1000; j++) {
        if (j % a == boy[i] &&
            find(girl.begin(), girl.end(), j % b) == girl.end()) {
          if (j < b) {
            girl.push_back(j);
          }
          if (find(boy.begin(), boy.end(), j % b) == boy.end() && j % b < a) {
            boy.push_back(j % b);
          }
        }
      }
    }
    for (int i = 0; i < girl.size(); i++) {
      for (int j = 0; j <= 1000; j++) {
        if (j % b == girl[i] &&
            find(boy.begin(), boy.end(), j % a) == boy.end()) {
          if (j < a) {
            boy.push_back(j);
          }
          if (find(girl.begin(), girl.end(), j % a) == girl.end() &&
              j % a < b) {
            girl.push_back(j % a);
          }
        }
      }
    }
  } else {
    for (int i = 0; i < girl.size(); i++) {
      for (int j = 0; j <= 1000; j++) {
        if (j % b == girl[i] &&
            find(boy.begin(), boy.end(), j % a) == boy.end()) {
          if (j < a) {
            boy.push_back(j);
          }
          if (find(girl.begin(), girl.end(), j % a) == girl.end() &&
              j % a < b) {
            girl.push_back(j % a);
          }
        }
      }
    }
    for (int i = 0; i < boy.size(); i++) {
      for (int j = 0; j <= 1000; j++) {
        if (j % a == boy[i] &&
            find(girl.begin(), girl.end(), j % b) == girl.end()) {
          if (j < b) {
            girl.push_back(j);
          }
          if (find(boy.begin(), boy.end(), j % b) == boy.end() && j % b < a) {
            boy.push_back(j % b);
          }
        }
      }
    }
  }
  if (boy.size() == a && girl.size() == b) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
  return 0;
}
