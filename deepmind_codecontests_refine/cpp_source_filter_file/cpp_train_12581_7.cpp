#include <iostream>
#include <string>

using namespace std;

int main(){
	int s;
	cin >> s;
	int a = s.find("a");
	int z = s.rfind("z");
	cout << z - a + 1 << endl;
	return 0;
}