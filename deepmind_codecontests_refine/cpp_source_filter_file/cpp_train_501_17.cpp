#include<bits/stdc++.h>
using namespace std;

int main(){
int a;
  cin>>a;
  vector<int> b(a);
  for(int i=0;i<s;i++)
    cin>>b.at(i);
  sort(b.begin(),b.end());
  cout<<b.at(a-1)-b.at(0)<<endl;
}