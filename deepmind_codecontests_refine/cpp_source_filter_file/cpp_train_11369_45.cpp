#include <bits/stdc++.h>
using namespace std;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s;
  cin >> s;
  long long len = s.length();
  bool end = 0;
  long long index = 0;
  long long spaces = 0;
  while (index < len) {
    index++;
    if (s[index] == '/') {
      end = 1;
      index++;
    }
    long long startI = index, endI = index;
    while (index < len && s[index] != '>') {
      index++;
    }
    endI = index - 1;
    index++;
    if (end) {
      spaces--;
    }
    for (long long i = 0; i < spaces; i++) {
      cout << " ";
    }
    cout << "<";
    if (end) {
      cout << "/";
    }
    for (long long j = startI; j <= endI; j++) {
      cout << s[j];
    }
    cout << ">";
    if (end == 0) {
      spaces++;
    }
    end = 0;
    cout << endl;
  }
}
