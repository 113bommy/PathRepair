#include <bits/stdc++.h>
using namespace std;

int main(){
  vector<int> y(4,0); cin>>y[0]>>y[1]>>y[2]>>y[3];
  sort(y.begin(),y.end);
  if(y[0]=1 && y[1]==4 && y[2] ==7 && y[3]== 9) cout << "YES" << endl;
  else cout << "NO" << endl;
}