#include <bits/stdc++.h>
using namespace std;
int main() {
  long long int t;
  cin >> t;
  while (t--) {
    long long int n;
    cin >> n;
    map<long long int, long long int> m;
    m[1] = 1;
    m[11] = 3;
    m[111] = 6;
    m[1111] = 10;
    m[2] = 11;
    m[22] = 13;
    m[222] = 16;
    m[2222] = 20;
    m[3] = 21;
    m[33] = 23;
    m[333] = 26;
    m[3333] = 30;
    m[4] = 31;
    m[44] = 33;
    m[444] = 36;
    m[4444] = 40;
    m[5] = 41;
    m[55] = 43;
    m[555] = 46;
    m[5555] = 50;
    m[6] = 51;
    m[66] = 53;
    m[666] = 56;
    m[6666] = 60;
    m[7] = 61;
    m[77] = 63;
    m[777] = 66;
    m[7777] = 70;
    m[8] = 71;
    m[88] = 73;
    m[888] = 76;
    m[8888] = 80;
    m[9] = 81;
    m[99] = 83;
    m[999] = 86;
    m[9999] = 90;
    cout << m[n] << endl;
  }
}
