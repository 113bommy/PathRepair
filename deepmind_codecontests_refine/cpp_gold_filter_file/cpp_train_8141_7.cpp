#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int test_case;
  cin >> test_case;
  while (test_case--) {
    string str;
    cin >> str;
    long long count1 = 0;
    vector<int> vec;
    long long int i, j, t;
    for (i = 0; i < str.length(); i++) {
      long long int mark = 0;
      if (str[i] == 'o') {
        if (i + 2 <= str.length() - 1) {
          if (str[i + 1] == 'n' && str[i + 2] == 'e') {
            vec.push_back(i + 1);
            i = i + 2;
          }
        }
      } else if (str[i] == 't') {
        if (i + 4 <= str.length() - 1) {
          if (str[i + 1] == 'w' && str[i + 2] == 'o' && str[i + 3] == 'n' &&
              str[i + 4] == 'e') {
            vec.push_back(i + 2);
            i = i + 4;
            mark = 1;
          }
        }
        if (mark != 1) {
          if (i + 2 <= str.length() - 1) {
            if (str[i + 1] == 'w' && str[i + 2] == 'o') {
              vec.push_back(i + 1);
              i = i + 2;
            }
          }
        }
      } else {
        continue;
      }
    }
    cout << vec.size() << endl;
    for (i = 0; i < vec.size(); i++) {
      cout << vec.at(i) + 1 << " ";
    }
    cout << endl;
  }
}
