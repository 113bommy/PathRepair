#include<bits/stdc++.h>
using namespace std;

int main(){

    while(1){
        string s; cin >> s;
        if(s == "#") break;
        int y, m, d; cin >> y >> m >> d;
        string ans;
        if(y <= 30) ans = "HEISEI";
        else if(y >= 32){
            ans = "?";
            y -= 30
        }
        else{
            if(m <= 4) ans = "HEISEI";
            else{
                ans = "?";
                y -= 30;
            }
        }

        cout << ans << " " << y << " " << m << " " << d << endl;
    }
    return 0;
}
