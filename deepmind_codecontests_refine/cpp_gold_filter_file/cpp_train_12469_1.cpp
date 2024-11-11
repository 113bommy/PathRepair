#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll, ll>;

int main(){
    int d;
    cin>>d;
    int c[26];
    for(int i=0;i<26;i++)cin>>c[i];
    int s[d][26];
    for(int i=0;i<d;i++)for(int j=0;j<26;j++){
        cin>>s[i][j];
    }
    int t[d];
    for(int i=0;i<d;i++)cin>>t[i];
    int score=0;
    int last[26]={};
    for(int i=1;i<=d;i++){
        last[t[i-1]-1]=i;
        score+=s[i-1][t[i-1]-1];
        for(int j=0;j<26;j++){
            score-=(i-last[j])*c[j];
        }
        cout<<score<<endl;
    }
}