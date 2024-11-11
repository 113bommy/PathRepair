#include <bits/stdc++.h>
using namespace std;
int main(void){
    int n;
    cin >> n;
    char c;
    string s="";
    while(n--){
        cin >> c;
        s+=c;
    }
    for(int i=0; i<=1997; i++){//4桁は997個だけ1997より小さい
        if(s.find(to_string(i))==npos){//nposとは部分列が入っていないのをさす
            cout << i << "\n";
            break;
        }
    }
    
}

