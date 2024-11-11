clude <iostream>
using namespace std;
int main() {
	int A, B, C, D, E, K;
	cin >> A >> B >> C >> D >> E >> K;
	cout << (E - A <= K ? "Yay!" : ":(") << endl;
	return 0;
}