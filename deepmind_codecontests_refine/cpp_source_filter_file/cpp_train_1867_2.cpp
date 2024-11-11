#include <string>
#include <iostream>
using namespace std;
int n, a, c; string s;
int main() {
	scanf("%d", &n);
	for(int i = 0; i < n; i++) scanf("%d", &a), s += (char)(a + 48);
	while(true)
		if(s.find(to_string(c++)) == string::npos) {
			printf("%d\n", c--); break;
		}
	}
	return 0;
}