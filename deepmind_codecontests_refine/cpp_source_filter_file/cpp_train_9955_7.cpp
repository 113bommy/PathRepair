#include <bits/stdc++.h>
using namespace std;
int main() {
  string s;
  cin >> s;
  long long cnt = 0;
  for (long long i = 0; i < s.size(); i++) {
    if ((i + 4) < s.size() && s.substr(i, 5) == "Danil") {
      cnt++;
    }
    if ((i + 3) < s.size() && s.substr(i, 4) == "Olya") {
      cnt++;
    }
    if ((i + 4) < s.size() && s.substr(i, 4) == "Slava") {
      cnt++;
    }
    if ((i + 2) < s.size() && s.substr(i, 3) == "Ann") {
      cnt++;
    }
    if ((i + 5) < s.size() && s.substr(i, 6) == "Nikita") {
      cnt++;
    }
  }
  if (cnt == 1) {
    cout << "YES";
  } else {
    cout << "NO";
  }
}
