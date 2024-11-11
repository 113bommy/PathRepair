#include <bits/stdc++.h>
using namespace std;
int sD(int n) {
  if (n % 2 == 0) return 2;
  for (int i = 3; i * i <= n; i += 2) {
    if (n % i == 0) return i;
  }
  return n;
}
bool compare(const pair<int, int>& i, const pair<int, int>& j) {
  if (i.second < j.second) {
    return true;
  } else if (i.second == j.second) {
    return i.first < j.first;
  } else {
    return false;
  }
}
int check(int mas[], int i, int n) {
  if (mas[i] != -2) {
    int cur = mas[i] % 2;
    int k = mas[i];
    if (i + mas[i] < n && mas[i + k] % 2 != cur) {
      mas[i] = 1;
      return 1;
    } else if (i - mas[i] >= 0 && mas[i - k] % 2 != cur) {
      mas[i] = 1;
      return 1;
    } else if (i + mas[i] < n && i - mas[i] >= 0) {
      int he1 = check(mas, i + mas[i], n);
      int he2 = check(mas, i - mas[i], n);
      if (he1 > 0 && he2 > 0) {
        mas[i] = 1 + min(he1, he2);
      } else if (he1 > 0) {
        mas[i] = 1 + he1;
      } else if (he2 > 0) {
        mas[i] = 1 + he2;
      } else {
        mas[i] = -1;
      }
    } else if (i + mas[i] < n) {
      int he1 = check(mas, i + mas[i], n);
      if (he1 > 0) {
        mas[i] = 1 + he1;
      }
      mas[i] = 1 + he1;
    } else if (i - mas[i] >= 0) {
      int he1 = check(mas, i - mas[i], n);
      if (he1 > 0) {
        mas[i] = 1 + he1;
      }
      mas[i] = 1 + he1;
    } else {
      mas[i] = -1;
    }
    return mas[i];
  }
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);
  int ku;
  cin >> ku;
  string cur;
  vector<int> ans;
  for (int qw = 0; qw < ku; qw++) {
    cin >> cur;
    ans.clear();
    int tw = 0;
    int one = 0;
    int toh = 0;
    for (int i = 0; i < cur.length(); i++) {
      if (cur[i] == 't') {
        one = 0;
        tw = 1;
      } else if (cur[i] == 'w') {
        if (tw == 1) {
          tw = 2;
        } else {
          tw = 0;
        }
        one = 0;
      } else if (cur[i] == 'o') {
        if (tw == 2) {
          tw = 3;
        } else {
          tw = 0;
        }
        one = 1;
      } else if (cur[i] == 'n') {
        tw = 0;
        if (one == 1) {
          one = 2;
        } else {
          one = 0;
        }
      } else if (cur[i] == 'e') {
        tw = 0;
        if (one == 2) {
          one = 3;
        } else {
          one = 0;
        }
      } else {
        one = 0;
        tw = 0;
      }
      if (tw == 3) {
        if (i + 2 < cur.length()) {
          if (cur[i + 1] == 'n' && cur[i + 1] == 'e') {
            ans.push_back(i);
            tw = 2;
            one = 0;
          } else {
            ans.push_back(i - 1);
            tw = 0;
          }
        } else {
          ans.push_back(i - 1);
          tw = 0;
        }
      }
      if (one == 3) {
        ans.push_back(i - 1);
        one = 1;
      }
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) {
      cout << ans[i] + 1 << " ";
    }
    cout << endl;
  }
  return 0;
}
