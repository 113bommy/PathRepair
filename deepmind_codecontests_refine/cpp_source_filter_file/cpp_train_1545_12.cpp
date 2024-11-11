#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
int n;
cin>>n;
string tmp;
map<string, int> score;
for(int i=0; i<n; ++i){
cin>>tmp;
score[tmp]++;
}
cin>>n;
for(int i=0; i<n; ++i){
cin>>tmp;
score[tmp]--;
}
int s=0;
for(auto i:score) s=max(s, i->second);
cout<<s<<endl;
}