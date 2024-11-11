#include <bits/stdc++.h>
using namespace std;
int main(){
	int n,i,a;
	set <int> s;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(s.find(a)==s.end())
		s.insert(a);
		else{
			s.erase(a);
		}
	}
	printf("%d",s.size());
}