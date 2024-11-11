#include <bits/stdc++.h>
using namespace std;
string str[4000], placed[4000];
int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  string temp = "Ab", t = "cdefghijklmnop", str1, str2;
  int k = 0;
  for (int i = 0; i < 15; i++) {
    for (int j = 0; j < 15; j++) {
      for (int l = 0; l < 15; l++) {
        str[k++] = temp + t[i] + t[j] + t[l];
      }
    }
  }
  int n, m;
  cin >> n >> m;
  int rem = (n - m + 1);
  cin >> str1;
  if (str1 == "NO") {
    cout << str[0] << " ";
    cout << str[0] << " ";
    placed[0] = str[0], placed[1] = str[0];
    for (int i = 1; i < m - 1; i++) {
      cout << str[i] << " ";
      placed[i + 1] = str[i];
    }
    k = m - 1;
  } else {
    for (int i = 0; i < m; i++) {
      cout << str[i] << " ";
      placed[i] = str[i];
    }
    k = m;
  }
  for (int i = m; i < n; i++) {
    cin >> str1;
    if (str1 == "YES") {
      cout << str[k] << " ";
      placed[i] = str[k];
      k++;
    } else {
      cout << placed[i - m + 1] << " ";
      placed[i] = placed[i - m + 1];
    }
  }
  cout << endl;
  return 0;
}
