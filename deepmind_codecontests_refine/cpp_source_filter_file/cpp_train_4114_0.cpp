#include <bits/stdc++.h>
using namespace std;
bool isDelimiter(char ch) { return ch == ';' || ch == ','; }
int main() {
  string sample;
  while (cin >> sample) {
    vector<string> a, b;
    bool inside = true, isWord = false, extra = false;
    int len = sample.length();
    string temp;
    for (int i = 0; i < len; i++) {
      temp += sample[i];
      if (!inside && i < len - 1 && !isDelimiter(sample[i + 1]) &&
          sample[i] == '0')
        isWord = true;
      inside = true;
      if (!isWord && (sample[i] == '.' || isalpha(sample[i]))) isWord = true;
      if (sample[i] == ';' || sample[i] == ',' || i == len - 1) {
        if (isDelimiter(sample[i]))
          if (i < len - 1)
            temp.erase(temp.end() - 1);
          else {
            temp.erase(temp.end() - 1);
            extra = true;
          }
        inside = false;
        if (isWord || temp.empty()) {
          isWord = false;
          b.push_back(temp);
        } else
          a.push_back(temp);
        if (extra) b.push_back("");
        temp.clear();
      }
    }
    if (a.size()) {
      cout << "\"";
      for (int i = 0; i < a.size(); i++)
        cout << a[i] << ",\""[i == a.size() - 1];
      cout << endl;
    } else
      cout << "-" << endl;
    if (b.size()) {
      cout << "\"";
      for (int i = 0; i < b.size(); i++)
        cout << b[i] << ",\""[i == b.size() - 1];
      cout << endl;
    } else
      cout << "-" << endl;
  }
  return 0;
}
