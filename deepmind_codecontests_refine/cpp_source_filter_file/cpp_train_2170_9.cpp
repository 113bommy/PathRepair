#include<bits/stdc++.h>
using namespace std;
int main(){
int n;
cin >> n;
vector<int>vec(n);
for(int i=0;i<n;i++){
  cin >> vec.at(i);
}
int sub=1;
  for(int i=0;i<n;i++){
  if(vec.at(i)%2==0){
  sub*=2;
  else sub*=1;}
  }
  cout << pow(3,n) - sub << endl; 
}
