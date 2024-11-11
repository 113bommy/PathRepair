#include <bits/stdc++.h>
using namespace std;
int main() {
  string in;
  cin >> in;
  long long count = 0;
  for (int i = 0; i < in.size() - 1; i++) {
    int div4_1 = in[i] - '0';
    if (div4_1 % 4 == 0) {
      count++;
    }
    string test = "";
    char num[2];
    num[0] = in[i];
    num[1] = in[i + 1];
    test.append(num);
    int div4_2 = atoi(test.c_str());
    if (div4_2 % 4 == 0) {
      count = count + i + 1;
    }
  }
  int div4_1 = in[in.size() - 1] - '0';
  if (div4_1 % 4 == 0) {
    count++;
  }
  cout << count;
  return 0;
}
