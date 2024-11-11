#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin>>S;
    int f=0,x=stoi(S);
    for(int i=0;i<S.size();++i) f+=S[i]-'0';
    puts(!(x%f)?"Yes":"No");
}