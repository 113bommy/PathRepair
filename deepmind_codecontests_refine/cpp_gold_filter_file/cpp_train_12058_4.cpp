#include<bits/stdc++.h>
using namespace std;

long long int N;
string s;
char c = -1;
set<string> S;

int main(){
    cin >> N;
    for(int i = 0; i < N; ++i){
        cin >> s;
        if(c >= 0 && c != s[0])return 0 & puts("No");
        c = *s.rbegin();
        if(!S.insert(s).second)return 0 & puts("No");
    }
    puts("Yes");
    return 0;
}
