#include <bits/stdc++.h>
using namespace std;
int main() {
  long long t = 0;
  cin >> t;
  for (long long i = 0; i < t; i++) {
    long long a, b;
    cin >> a >> b;
    string stra = bitset<20>(a).to_string();
    string strb = bitset<20>(b).to_string();
    for (int i = 0; i < strb.size(); i++) {
      if (stra[i] == strb[i] && strb[i] == '1') {
        stra[i] = '0';
        strb[i] = '0';
      }
    }
    long long anew = bitset<20>(stra).to_ulong();
    long long bnew = bitset<20>(strb).to_ulong();
    cout << anew + bnew << '\n';
  }
  return 0;
}
