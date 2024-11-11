#include<iostream>
#include<stack>
using namespace std;

int main()
{
	int x;
	stack<int> st;
	while (cin >> x) {
		if (x) {
			st.push(x);
		}
		else {
			cout << st.top() << endl;
			st.pop();
		}
	}
    return 0;
}