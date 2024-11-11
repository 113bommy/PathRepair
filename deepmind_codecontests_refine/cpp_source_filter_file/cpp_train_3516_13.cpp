#include <bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin>>n;
	int x=0;
	long long int int a[300000];
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)x=x^a[i];
	for(int i=0;i<n;i++)a[i]=x^a[i];
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
