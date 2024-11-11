#include <bits/stdc++.h>
using namespace std;

int main() {
   int n;
  cin >> n;
  map<string, int> cnt;
  for (i = 0; i < n; i++){
    string s ;
    cin >> s;
    cnt[s]++;
  }
  for(string x : {"AC", "WA", "TLE", "RE"}){
    cout << x << " x " << cnt[x] << endl;
  
  }