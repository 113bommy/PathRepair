#include <bits/stdc++.h>
std::vector<long long> values;
std::vector<long long> left;
std::vector<std::vector<bool>> palindrom;
std::string line;
std::vector<int> entry[26];
bool ispalindrom(int start, int finish) {
  for (int i = 0; i <= (finish - start) / 2; i++) {
    if (line[start + i] != line[finish - i]) return false;
  }
  return true;
}
int main() {
  std::cin >> line;
  values.resize(line.length());
  left.resize(line.length());
  palindrom.resize(line.length());
  for (int i = 0; i < line.length(); i++) palindrom[i].resize(line.length());
  for (int j = 0; j < line.length(); j++) {
    palindrom[j][j] = true;
    left[j]++;
    int i = 1;
    while ((j + i < line.length()) && (j - i >= 0)) {
      if (line[j + i] == line[j - i]) {
        palindrom[j - i][j + i] = true;
        left[j + i]++;
      } else {
        break;
      };
      i++;
    }
  }
  for (int j = 0; j < line.length() - 1; j++) {
    int i = 0;
    if (line[j] != line[j + 1]) continue;
    while ((j - i >= 0) && (j + 1 + i < line.length())) {
      if (line[j - i] == line[j + 1 + i]) {
        palindrom[j - i][j + 1 + i] = true;
        left[j + 1 + i]++;
      } else {
        break;
      }
      i++;
    }
  }
  for (int j = 1; j < line.length(); j++) {
    left[j] += left[j - 1];
  }
  values[0] = 0;
  values[1] = 1;
  for (int i = 2; i < line.length(); i++) {
    values[i] = values[i - 1];
    for (int j = 1; j <= i; j++) {
      if (palindrom[j][i]) {
        values[i] += left[j - 1];
      }
    }
  }
  std::cout << values[line.length() - 1];
}
