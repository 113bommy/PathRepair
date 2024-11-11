#include <bits/stdc++.h>
using namespace std;

int main(){
int a,b,c,s;
cin >> a >> b >> c;
s=max({a,b,c});
cout << a+b+c-s+s*10 << endl;
}