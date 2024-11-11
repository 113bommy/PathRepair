#include<iostream>
#include<utility>
#include<string>
#include<algorithm>
using namespace std;
char in[120];
pair<pair<string,int>,int> p;
int main(){
int a;
cin>>a;
for(int i=0;i<a;i++){
int t;
  cin>>in>>t;
string tmp=in;
p[i]=make_pair(make_pair(in,-t),i);
}
sort(p,p+a);
for(int i=0;i<a;i++)printf("%d\n",p[i].second+1);
}
