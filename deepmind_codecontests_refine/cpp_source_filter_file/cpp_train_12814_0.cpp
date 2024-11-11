#include <bits/stdc++.h>
using namespace std;
int main() {
  int n, count = 0, k = 0;
  cin >> n;
  string str1, str2;
  cin >> str1 >> str2;
  vector<int> v;
  map<char, int> mp1, mp2;
  for (int i = 0; i < str1.length(); i++) mp1[str1[i]]++;
  for (int i = 0; i < str2.length(); i++) mp2[str2[i]]++;
  if (mp1 != mp2)
    cout << -1 << "\n";
  else {
    int i = 0;
    while (str1 != str2 && k <= 10000) {
      if (str1[i] == str2[i]) {
        i++;
        continue;
      } else {
        int j = 0;
        for (j = i + 1; j < str1.length(); j++) {
          if (str1[j] == str2[i]) break;
        }
        while (str1[i] != str2[i] && j > i) {
          v.push_back(j - 1);
          swap(str1[j], str1[j - 1]);
          j--;
          count++;
        }
      }
    }
    cout << count << "\n";
    for (int i = 0; i < v.size(); i++) {
      cout << v[i] << " ";
    }
    cout << "\n";
  }
}
