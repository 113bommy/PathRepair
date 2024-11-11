#include <bits/stdc++.h>
using namespace std;
long long start[26][131072 + 1];
long long end2[26][131072 + 1];
long long fn(string second, long long low, long long end, char c) {
  long long n = second.length();
  if (n == 1) {
    if (second[0] == c)
      return 0;
    else
      return 1;
  }
  string s1 = "", s2 = "";
  long long i;
  long long count1 = 0, count2 = 0;
  s1 = second.substr(0, n / 2);
  s2 = second.substr(n / 2, n / 2);
  long long mid = low + (end - low) / 2;
  count1 = n / 2 - (start[c - 'a'][mid]);
  if (low != 0) count1 += start[c - 'a'][low - 1];
  count2 = n / 2 - (start[c - 'a'][end] - start[c - 'a'][mid]);
  return min(count1 + fn(s2, mid + 1, end, c + 1),
             count2 + fn(s1, low, mid, c + 1));
}
int main() {
  long long t;
  cin >> t;
  while (t--) {
    long long n;
    cin >> n;
    string second;
    cin >> second;
    map<char, long long> m;
    for (long long i = 0; i < n; i++) {
      m[second[i]]++;
      for (long long j = 0; j < 26; j++) {
        start[j][i] = m['a' + j];
      }
    }
    m.clear();
    long long i;
    for (i = n - 1; i >= 0; i--) {
      m[second[i]]++;
      for (long long j = 0; j < 26; j++) {
        end2[j][i] = m['a' + j];
      }
    }
    cout << fn(second, 0, n - 1, 'a');
  }
}
