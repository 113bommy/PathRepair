#include <bits/stdc++.h>
using namespace std;

int main(){

 int N,P;
 cin >> N;
 string s;
 pair<pair<string,int>,int> p[110];

 for(int i=0;i<N;i++){
 cin>>s>>P;
 p[i]=make_pair(make_pair(s,-P),i);
 }

 sort(p,p+a);

 for(int i=0;i<N;i++){
 printf("%d\n",p[i].second+1);
}
 return 0;
}