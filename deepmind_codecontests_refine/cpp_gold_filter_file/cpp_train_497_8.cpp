#include<bits/stdc++.h>
using namespace std;
int main(){
int N;
string s;
cin >> N >> s;
int r = 0;
int b = 0;
for(int i=0;i<N;i++){
if(s.at(i) == 'R') r++;
else b++;
}
if(r > b) cout << "Yes" <<endl;
else cout << "No" << endl;
}
