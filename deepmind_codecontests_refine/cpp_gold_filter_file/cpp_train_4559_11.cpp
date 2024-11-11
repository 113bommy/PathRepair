#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int A,B,m;
  cin >> A >> B >> m;
  vector<int> a(A);
  for(int i=0;i<A;i++) cin >> a.at(i);
  vector<int> b(B);
  for(int i=0;i<B;i++) cin >> b.at(i);
  
  int money=200000;
  
  for(int i=0;i<m;i++){
    int x,y,z;
    cin >> x >> y >> z;
    money=min(money,a.at(x-1)+b.at(y-1)-z);
  }
  sort(a.begin(),a.end());
  sort(b.begin(),b.end());
  cout << min(money,a.at(0)+b.at(0)) << endl;
}