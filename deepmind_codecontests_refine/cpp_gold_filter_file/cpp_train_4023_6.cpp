#include <bits/stdc++.h>
using namespace std;
long long int expo_fast(long long int a, long long int b) {
  a = a;
  long long int result = 1;
  while (b) {
    if (b & 1) result = (result * a);
    b >>= 1;
    a = (a * a);
  }
  return (result);
}
void take_in(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cin >> (*(arr))[i];
}
void disp_arr(vector<long long int>* arr) {
  for (int i = 0; i < arr->size(); i++) cout << (*(arr))[i] << " ";
}
long long int gcd(long long int a, long long int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}
bool cmp(const pair<pair<int, int>, long long int> a,
         const pair<pair<int, int>, long long int> b) {
  if (a.first.first < b.first.first)
    return true;
  else if (a.first.first == b.first.first) {
    return a.first.second < b.first.second;
  } else
    return false;
}
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  int n;
  cin >> n;
  vector<pair<char, string>> inp(n);
  for (int i = 0; i < n; i++) {
    char c;
    cin >> c;
    string s;
    cin >> s;
    inp[i] = make_pair(c, s);
  }
  vector<int> color(26);
  int count_susp = 0, shit_count = 0;
  bool done = false;
  int ans = 0;
  char selected = NULL;
  bool shock = false;
  int k = 0;
  for (k = 0; k < n; k++) {
    pair<char, string> x = inp[k];
    if (!done) {
      if (x.first == '.' || (k != n - 1 && x.first == '?')) {
        for (int i = 0; i < x.second.length(); i++) {
          if (color[x.second[i] - 'a'] == 0) {
            color[x.second[i] - 'a'] = 2;
            shit_count++;
          }
        }
        if (shit_count >= 25) {
          done = true;
          for (int i = 0; i < 26; i++) {
            if (color[i] == 0) {
              selected = (char)('a' + i);
              break;
            }
          }
        }
      } else if (x.first == '!') {
        shock = true;
        for (int i = 0; i < x.second.length(); i++) {
          if (color[x.second[i] - 'a'] == 0) {
            color[x.second[i] - 'a'] = 1;
            count_susp++;
          }
        }
        break;
      }
    } else {
      if (x.first == '!')
        ans++;
      else if (x.first == '?' && x.second[0] != selected)
        ans++;
    }
  }
  if (!done) {
    for (int kk = k; kk < n; kk++) {
      pair<char, string> x = inp[kk];
      if (!done) {
        if (x.first == '!') {
          for (int i = 0; i < 26; i++) {
            if (color[i] == 1) {
              bool found = false;
              for (int j = 0; j < x.second.length(); j++) {
                if (x.second[j] == (char)('a' + i)) {
                  found = true;
                  break;
                }
              }
              if (!found) {
                color[i] = 2;
                count_susp--;
              }
            }
          }
          if (count_susp == 1) {
            done = true;
            for (int i = 0; i < 26; i++) {
              if (color[i] == 1) {
                selected = (char)('a' + i);
                break;
              }
            }
          }
        } else if (x.first == '.' || (x.first == '?' && k != n - 1)) {
          for (int i = 0; i < x.second.length(); i++) {
            if (color[x.second[i] - 'a'] == 1) {
              color[x.second[i] - 'a'] = 2;
              count_susp--;
            } else
              color[x.second[i] - 'a'] = 2;
          }
          if (count_susp == 1) {
            done = true;
            for (int i = 0; i < 26; i++) {
              if (color[i] == 1) {
                selected = (char)('a' + i);
                break;
              }
            }
          }
        }
      } else {
        if (x.first == '!')
          ans++;
        else if (x.first == '?' && x.second[0] != selected)
          ans++;
      }
    }
  }
  cout << ans;
}
