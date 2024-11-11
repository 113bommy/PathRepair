#include <iostream>;
using namespace std;
int main() {
	int n; cin >> n;
	string s; cin >> s;
  	bool w = 1;
    for (int i = 0; i < n / 2; i+++) w &= s[i] == s[i + n / 2];
  	cout << (w ? "Yes" : "No") << endl;
  	return 0;
}
