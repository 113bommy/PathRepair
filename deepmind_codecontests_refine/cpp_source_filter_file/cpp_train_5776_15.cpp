#include <bits/stdc++.h>
using namespace std;
vector<int> d(500001);
vector<int> arr(500001);
string st;
bool isvowel(char ch) {
  return (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' ||
          ch == 'Y');
}
int getnum(int m) {
  int left = m;
  int right = st.size() - m + 1;
  return (d[right] - d[left - 1]);
}
int main() {
  cin >> st;
  int num = 0;
  for (int i = 1; i <= st.size(); i++) {
    if (isvowel(st[i - 1])) num++;
    d[i] = num;
  }
  int sz = st.size() + 1;
  for (int i = 1; i <= sz / 2; i++) {
    arr[i] = arr[i - 1] + getnum(i);
  }
  double rest = 0.0;
  for (int i = 1; i <= sz / 2; i++) {
    double up = arr[i];
    double down = i;
    rest += up / down;
    down = st.size() - i + 1;
    if (st.size() - i + 1 != i) rest += up / down;
  }
  printf("%.9f", rest);
  return 0;
}
