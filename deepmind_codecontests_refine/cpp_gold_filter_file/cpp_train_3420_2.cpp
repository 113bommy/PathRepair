#include <bits/stdc++.h>
 
using namespace std;
 
string s[10001], smin[10001], smax[10001], target;
int strict, pos, n;
 
int main(){
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>s[i];
        smin[i]=s[i];
        smax[i]=s[i];
        for(int j=0; j<s[i].size(); j++){
            if(s[i][j]=='?')smin[i][j]='a';
            if(s[i][j]=='?')smax[i][j]='z';
        }
    }
    cin>>target;
    for(int i=0; i<n; i++){
        if(smin[i]<=target && target<=smax[i]){
            pos++;
        }
        if(smax[i]<target){
            strict++;
        }
    }
    for(int i=0; i<pos; i++){
        cout<<strict+i+1<<" ";
    }
    cout << strict+1+pos << endl;
}