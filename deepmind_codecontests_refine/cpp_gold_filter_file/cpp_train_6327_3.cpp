#include<bits/stdc++.h>
using namespace std;
int main () {
  int h, m, h_, w_, K;
  cin >> h >> m >> h_ >> w_ >> K;
  cout << (h_ - h) * 60 + w_ - m - K << endl;
}
