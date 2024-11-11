#include<bits/stdc++.h>
using namespace std;

int n;
void solve(string now, char mx){
    if(now.length()==n)cout << now << endl;
    else{
        for(char c='a';c<=mx;c++){
            if(c<mx) solve(now+c,mx);
            else solve(now+c,mx+1);
        }
    }
}
int main(){
    cin >> n;
    solve("",'a');
}