/*#include <iostream>
#include <string>
using namespace std;

int main(){
	 ios::sync_with_stdio(false);
	string a, b;
	int x, i = 0;
	cin >> a >> b;
	for(int i = 0;a[i];i++){
		i = a.find(b, i);
		if(i == -1)break;
		cout << i << endl;
	}
	while((x = a.find(b, i)) != -1){
		cout << x << endl;
		i = x + 1;
	}
	return 0;
}*/

#include <iostream>
using namespace std;string t,p;int main(){ios::sync_with_stdio(false);cin>>t>>p;for(int i=0;t[i];i++){i=t.find(p, i);if(i==string::npos)break;cout<<i<<'\n';}return 0;}