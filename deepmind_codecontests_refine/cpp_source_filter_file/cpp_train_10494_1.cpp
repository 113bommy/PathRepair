#include<iostream>
using namespace std;

// I hate
int main(){
    int n, a, b, c, d;
    string s;
    cin >> n >> a >> b >> c >> d >> s;
    a--, b--, c--, d--;
    bool valid = true;    
    if(c > d){ // snuke overtakes the other
        valid = false;
        for(int i = b-1; i+2 <= d; i++){
            valid |= (s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.');
        }
    }
    for(int i = a; i+1 < c; i++){
        valid &= (s[i]=='.' || s[i+1]=='.');
    }
    for(int i = b; i+1 < d; i++){
        valid &= (s[i]=='.' || s[i+1]=='.');
    }
    cout << (valid ? "Yes" : "No") << endl;
    return 0;
}