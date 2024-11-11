#include<bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int sou=0;
    for(int i=0;i<s.size();i++){
        if((s[i]+i)%2!=0)sou++;//頭白とする
    }
    cout << min(sou,int(s.size()-sou)) << endl;
}