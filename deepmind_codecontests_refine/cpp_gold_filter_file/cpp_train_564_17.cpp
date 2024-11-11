#include <bits/stdc++.h>
using namespace std;
signed main() {
  std::vector<long long> v(27), v1(27);
  string second, s1;
  cin >> second >> s1;
  long long l1 = second.length(), l2 = s1.length();
  for (long long i = 0; i < l1; i++) {
    v[second[i] - 'a']++;
  }
  for (long long i = 0; i < l2; i++) {
    v1[s1[i] - 'a']++;
  }
  if (v == v1)
    cout << "array";
  else {
    if (l1 <= l2)
      cout << "need tree";
    else {
      long long n = 0;
      for (long long i = 0; i < l1 and n < l2; i++) n += second[i] == s1[n];
      if (n == l2)
        cout << "automaton";
      else {
        long long k = 0;
        for (long long i = 0; i < l2; i++) {
          size_t p = second.find(s1[i]);
          if (p != string::npos) k++;
          second[p] = '0';
        }
        if (k == l2)
          cout << "both";
        else
          cout << "need tree";
      }
    }
  }
}
