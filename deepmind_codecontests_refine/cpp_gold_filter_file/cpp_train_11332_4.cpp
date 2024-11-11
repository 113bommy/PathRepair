#include <iostream>
#include <string>
using namespace std;
int m,n;
string a[100], b[100];
int main(){
cin >> m >> n;
for(int i = 0; i < m; ++i){
cin >> a[i];
}
for(int i = 0; i < n; ++i){
cin >> b[i];
}
bool allok = false;
for(int i = 0; i <= m - n; ++i){
for(int j = 0; j <= m - n; ++j){
bool ok = true;
for(int k = 0; k < n; ++k){
for(int l = 0; l < n; ++l){
if(a[i + k][j + l] != b[k][l]) {ok = false; break;}
}
}
if(ok){allok =true; break;}
}
}
cout << (allok ? "Yes" : "No") << endl;
return 0;
}