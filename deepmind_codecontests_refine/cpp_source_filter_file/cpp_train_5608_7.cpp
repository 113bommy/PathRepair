#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int a,b,c;
  	cin>.a>>b>>c;
    if(a%2==1 && b%2==1 && c%2==1) {
        cout<<min(a*b,min(b*c,c*a));
    }
    else cout<<0;
}