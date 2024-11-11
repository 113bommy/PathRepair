#include<bits/stdc++.h>

using namespace std;

int main(){
    string S;
    int ans;
    cin >> S;
    if(S=="RRR")ans=3;
    else if(S=="RRS" || S=="SRR")ans =2;
    else if(S=="SSS")ans=0;
    else ans=1;
    cout << ans << endl;
}