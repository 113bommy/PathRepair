#include <bits/stdc++.h>
using namespace std;
int main() {
  char in[12];
  memset(&in, '\0', 12);
  cin >> in;
  const int l = strlen(in);
  bool t = false;
  char mas[10];
  int k = 1;
  mas[0] = in[0];
  for (int i = 1; i < l; ++i) {
    int j = 0;
    for (j = 0; j < k; ++j) {
      if (mas[j] == in[i]) break;
    }
    if (j == k) {
      mas[j] = in[i];
      ++k;
    }
  }
  char out[12];
  for (int i = 0; i <= l; ++i) {
    for (int j = 0; j < k; ++j) {
      memcpy(&out, &in, i);
      out[i] = mas[j];
      memcpy(out + i + 1, in + i, l - i);
      t = true;
      for (int z = 0; z <= l / 2; ++z) {
        if (out[z] != out[l - z]) {
          t = false;
          break;
        }
      }
      if (t) {
        memcpy(&in, &out, l + 1);
        break;
      }
    }
  }
  if (!t)
    cout << "NA\n";
  else
    cout << in << endl;
  return 0;
}
