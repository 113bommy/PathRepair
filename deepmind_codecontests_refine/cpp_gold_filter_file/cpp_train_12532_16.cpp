#include <bits/stdc++.h>
#pragma comment(linker, "/STACK:256000000")
using namespace std;
string num2str(int i) {
  stringstream ss;
  ss << i;
  return ss.str();
}
std::vector<std::string> Split(std::string str, std::string pattern) {
  std::string::size_type pos;
  std::vector<std::string> result;
  str += pattern;
  std::string::size_type size = str.size();
  for (int i = 0; i < size; i++) {
    pos = str.find(pattern, i);
    if (pos < size) {
      std::string s = str.substr(i, pos - i);
      result.push_back(s);
      i = pos + pattern.size() - 1;
    }
  }
  return result;
}
bool IsPrimer(int x) {
  if (x < 2) {
    return false;
  }
  for (int i = 2; i <= sqrt(double(x)); i++) {
    if (x % i == 0) {
      return false;
    }
  }
  return true;
}
template <typename T>
bool DesCmp(T a, T b) {
  return a > b;
}
template <typename T>
void Swap(T &a, T &b) {
  int temp = a;
  a = b;
  b = temp;
}
template <typename T>
void InputArray(T &a, int n) {
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
}
int main() {
  int n;
  scanf("%d", &n);
  string o[45];
  o[1] = "Washington";
  o[2] = "Adams";
  o[3] = "Jefferson";
  o[4] = "Madison";
  o[5] = "Monroe";
  o[6] = "Adams";
  o[7] = "Jackson";
  o[8] = "Van Buren";
  o[9] = "Harrison";
  o[10] = "Tyler";
  o[11] = "Polk";
  o[12] = "Taylor";
  o[13] = "Fillmore";
  o[14] = "Pierce";
  o[15] = "Buchanan";
  o[16] = "Lincoln";
  o[17] = "Johnson";
  o[18] = "Grant";
  o[19] = "Hayes";
  o[20] = "Garfield";
  o[21] = "Arthur";
  o[22] = "Cleveland";
  o[23] = "Harrison";
  o[24] = "Cleveland";
  o[25] = "McKinley";
  o[26] = "Roosevelt";
  o[27] = "Taft";
  o[28] = "Wilson";
  o[29] = "Harding";
  o[30] = "Coolidge";
  o[31] = "Hoover";
  o[32] = "Roosevelt";
  o[33] = "Truman";
  o[34] = "Eisenhower";
  o[35] = "Kennedy";
  o[36] = "Johnson";
  o[37] = "Nixon";
  o[38] = "Ford";
  o[39] = "Carter";
  o[40] = "Reagan";
  cout << o[n] << endl;
  return 0;
}
