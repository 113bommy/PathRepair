#include <bits/stdc++.h>
using namespace std;
string st;
bool ispalindrome(string a) {
  int index = a.size() - 1;
  for (int i = 0; i < (int)a.size() / 2; ++i) {
    if (a[i] != a[index]) return false;
    index--;
  }
  return true;
}
string falta(int k) {
  string aux;
  for (int i = k; i < (int)st.size(); ++i) {
    aux += st[i];
  }
  return aux;
}
int main() {
  cin >> st;
  string aux1, aux3;
  aux1 = st + st[0];
  aux3 = st[st.size() - 1] + st;
  if (ispalindrome(aux1)) {
    cout << aux1 << endl;
    return 0;
  }
  if (ispalindrome(aux3)) {
    cout << aux3 << endl;
    return 0;
  }
  string aux;
  for (int i = 0; i < (int)st.size(); ++i) {
    aux += st[i];
    for (int j = 0; j < 26; ++j) {
      char c = j + 'a';
      string aux2 = c + falta(i + 1);
      if (ispalindrome(aux + aux2)) {
        cout << aux + aux2 << endl;
        return 0;
      }
    }
  }
  cout << "NA" << endl;
  return 0;
}
