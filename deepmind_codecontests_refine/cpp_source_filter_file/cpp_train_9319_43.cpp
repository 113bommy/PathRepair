#include <bits/stdc++.h>
using namespace std;
int main() {
  const int IM = 8;
  int numElem;
  cin >> numElem;
  string a[numElem];
  string b[numElem];
  int temp;
  for (int i = 0; i < numElem; i++) {
    cin >> temp;
    a[i] = bitset<IM>(temp).to_string();
  }
  for (int i = 0; i < numElem; i++) {
    cin >> temp;
    b[i] = bitset<IM>(temp).to_string();
  }
  string binA = "";
  string binB = "";
  for (int i = 0; i < IM; i++) {
    binA += (a[0].at(i) == '1') ? "1" : "0";
    binB += (b[0].at(i) == '1') ? "1" : "0";
  }
  for (int i = 1; i < numElem; i++) {
    for (int j = 0; j < IM; j++) {
      if (a[i].at(j) == '1') binA[j] = '1';
      if (b[i].at(j) == '1') binB[j] = '1';
    }
  }
  long decA = bitset<8>(binA).to_ulong();
  long decB = bitset<8>(binB).to_ulong();
  cout << decA + decB;
  return 0;
}
