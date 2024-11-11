#include <bits/stdc++.h>
using namespace std;
map<string, string> hendl1, hendl2;
string s1[2001], s2[2001];
long n, k;
int main(int argc, char** argv) {
  cin >> n;
  for (long i = 1; i <= n; i++) {
    cin >> s1[i] >> s2[i];
    hendl1[s1[i]] = "Niht";
    hendl2[s2[i]] = "Niht";
    hendl1[s2[i]] = "Niht";
    hendl2[s1[i]] = "Niht";
  }
  for (long i = 1; i <= n; i++) {
    if (hendl2[s1[i]] == "Niht") {
      hendl1[s1[i]] = s2[i];
      hendl2[s2[i]] = s1[i];
      k++;
    } else {
      hendl1[hendl2[s1[i]]] = s2[i];
      hendl2[s2[i]] = hendl1[hendl2[s1[i]]];
    }
  }
  cout << k;
  for (long i = 1; i <= n; i++) {
    if (hendl1[s1[i]] != "Niht")
      cout << endl << hendl2[s2[i]] << " " << hendl1[s1[i]];
  }
  return 0;
}
