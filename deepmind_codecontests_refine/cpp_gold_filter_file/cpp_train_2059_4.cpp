#include <bits/stdc++.h>
using namespace std;
long long A,V,B,W,T;
int main(){
	cin>>A>>V;
	cin>>B>>W;
	cin>>T;
	puts(abs(A-B)<=T*(V-W)?"YES":"NO");
}