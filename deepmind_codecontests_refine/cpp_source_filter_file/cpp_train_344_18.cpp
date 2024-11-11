#include <bits/stdc++.h>
using namespace std;
using ll = long long int;
string s, t;
int mp[28], tempMap[28];
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int i, j, len1, len2, can = -1;
  cin >> s >> t;
  len1 = (int)s.size(), len2 = (int)t.size();
  for (i = 0; i < len1; i++) {
    mp[s[i] - 'a']++;
  }
  int rng = min(len1, len2) - 1;
  if (len1 > len2) rng++;
  for (i = 0; i < rng; i++) {
    if (mp[t[i] - 'a']) {
      mp[t[i] - 'a']--;
      for (j = 0; j < 26; j++) {
        tempMap[j] = mp[j];
      }
      bool flag = false;
      if (i == len2 - 1) {
        if (len1 > len2 && i == rng - 1) flag = true, can = i;
      } else {
        for (j = t[i + 1] - 'a' + 1; j < 26; j++) {
          if (mp[j]) {
            flag = true;
            break;
          }
        }
        if (flag) can = i;
      }
    } else {
      break;
    }
  }
  memset(mp, 0, sizeof mp);
  for (i = 0; i < len1; i++) mp[s[i] - 'a']++;
  if (can == -1) {
    int found = -1;
    for (i = t[0] - 'a' + 1; i < 26; i++) {
      if (mp[i]) {
        found = i;
        break;
      }
    }
    if (found == -1)
      cout << -1 << endl;
    else {
      cout << (char)(found + 'a');
      mp[found]--;
      for (i = 0; i < 26; i++) {
        for (j = 0; j < mp[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << endl;
    }
  } else {
    for (i = 0; i <= can; i++) {
      cout << t[i];
      mp[t[i] - 'a']--;
    }
    if (len1 > len2 && can == len2 - 1) {
      for (i = 0; i < 26; i++) {
        for (j = 0; j < mp[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << endl;
    } else {
      for (i = t[can] - 'a' + 1; i < 26; i++) {
        if (mp[i]) {
          cout << (char)(i + 'a');
          mp[i]--;
          break;
        }
      }
      for (i = 0; i < 26; i++) {
        for (j = 0; j < mp[i]; j++) {
          cout << (char)(i + 'a');
        }
      }
      cout << endl;
    }
  }
  return 0;
}
