#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int n;
  cin >> n;
  string w;
  string arr[100000];
  getline(cin, w);
  long long int cnt = 0;
  long long int cnt2 = 0;
  bool flag = false;
  string imp = "";
  for (int i = 0; i < n; i++) {
    getline(cin, w);
    arr[i] = w;
  }
  bool qwe = false;
  long long int j = 0;
  for (j = 0; j < n; j++) {
    w = arr[j];
    if (!qwe) {
      for (int i = 0; i < w.length(); i++) {
        if (w[i] == 't' && w[i + 1] == 'r') {
          cnt++;
          break;
        }
        if (w[i] == 'c') {
          cnt--;
          break;
        }
        if (w[i] == 't') {
          qwe = true;
          flag = true;
          i += 5;
          while (w[i] != '(') {
            i++;
          }
          i++;
          while (w[i] == ' ') {
            i++;
          }
          while (w[i] != ' ' && w[i] != ')') {
            imp += w[i];
            i++;
          }
          break;
        }
      }
    }
    if (qwe) {
      break;
    }
  }
  long long int z;
  for (z = j + 1; z < n; z++) {
    if (qwe) {
      if (cnt == 0 && flag) {
        cout << "1Unhandled Exception\n";
        return 0;
      }
      w = arr[z];
      for (int i = 0; i < w.length(); i++) {
        if (w[i] == 't') {
          cnt2++;
          break;
        }
        if (w[i] == 'c' && cnt2 == 0) {
          cnt--;
          i += 5;
          while (w[i] == ' ' || w[i] == '(') {
            i++;
          }
          bool some = true;
          for (int k = 0; k < imp.length(); k++) {
            if (imp[k] == w[i]) {
              i++;
              continue;
            }
            some = false;
          }
          if (!some) {
            break;
          } else {
            while (w[i] != '"') {
              i++;
            }
            i++;
            while (w[i] != '"') {
              cout << w[i++];
            }
            cout << endl;
            return 0;
          }
        } else if (w[i] == 'c' && cnt2 > 0) {
          cnt2--;
          break;
        }
      }
    }
  }
  cout << "Unhandled Exception\n";
  return 0;
}
