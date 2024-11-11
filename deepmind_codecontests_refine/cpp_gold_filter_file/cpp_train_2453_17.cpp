#include <bits/stdc++.h>
using namespace std;
int main() {
  int b = -1;
  vector<string> week;
  week.push_back("monday");
  week.push_back("tuesday");
  week.push_back("wednesday");
  week.push_back("thursday");
  week.push_back("friday");
  week.push_back("saturday");
  week.push_back("sunday");
  string str1, str2;
  cin >> str1 >> str2;
  int i = 0;
  while (i < 7) {
    vector<string> year;
    year.push_back(week[(i + 0) % 7]);
    year.push_back(week[(i + 3) % 7]);
    year.push_back(week[(i + 3) % 7]);
    year.push_back(week[(i + 6) % 7]);
    year.push_back(week[(i + 1) % 7]);
    year.push_back(week[(i + 4) % 7]);
    year.push_back(week[(i + 6) % 7]);
    year.push_back(week[(i + 2) % 7]);
    year.push_back(week[(i + 5) % 7]);
    year.push_back(week[(i + 0) % 7]);
    year.push_back(week[(i + 3) % 7]);
    year.push_back(week[(i + 5) % 7]);
    for (int k = 0; k + 1 < 12; k++) {
      if ((year[k] == str1) && (year[k + 1] == str2)) {
        b = 1;
        break;
      }
    }
    i++;
    if (b == 1) break;
  }
  if (b == 1)
    cout << "YES";
  else
    cout << "NO";
  return 0;
}
