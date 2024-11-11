#include<iostream>
#include<string>
#include<algorithm>
#include<bits/stdc++.h>
#include<vector>
 
using namespace std;
 
int main() {
  int N,co=0;
  cin >> N;
  string s,t;
  cin >> s >> t;
  for(int i=1; i<=N; i++){
    if(s.substr(N-i)==t.substr(0,i)) co=i;
  }
  cout << 2*N-co << endl;
}