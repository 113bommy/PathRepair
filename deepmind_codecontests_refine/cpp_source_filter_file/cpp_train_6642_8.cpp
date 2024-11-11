#include <bits/stdc++.h>
using namespace std;
int main() {
	String s,a,b; cin>>s;
	a=s.substring(0,2); b=s.substring(2,2);
	cout<<("00"<a&&a<"13"?"00"<b&&b<"13"?"AMBIGUOUS":"MMYY":"00"<b&&b<"13"?"YYMM":"NA";
}