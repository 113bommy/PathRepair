#include <bits/stdc++.h>
using namespace std;
int counts[26];
int main() {
  string s;
  cin >> s;
  int N = s.size();
  for (int i = 0; i < N; i++) counts[s[i] - 'a']++;
  for (int i = 0; i < 26; i++) {
    if (counts[i] % 2 == 1) {
      int k = -1;
      for (int j = 25; j >= 0 && k < 0; j--)
        if (counts[j] % 2 == 1) k = j;
      if (k != -1) counts[i]++, counts[k]--;
    }
  }
  int pos = 0;
  int middle = -1;
  for (int i = 0; i < 26; i++) {
    if (counts[i] % 2 == 1) {
      middle = i;
    }
    for (int j = 0; j + 1 < counts[i]; j += 2) {
      s[pos++] = 'a' + i;
      s[N - pos] = 'a' + i;
    }
  }
  if (middle != -1) s[N / 2] = middle + 'a';
  cout << s << endl;
}
