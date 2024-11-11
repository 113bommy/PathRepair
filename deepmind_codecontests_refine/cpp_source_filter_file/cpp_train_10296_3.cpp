#include <iostream>
#include <ostream>
#include <string>
using namespace std;
template < typename T > std::string to_string(const T& n)
{
	std::ostringstream stm;
	stm << n;
	return stm.str();
}
int main()
{
	int n, b = 0, c = 0;
	string Istr, Ostr;
	char ch;
	cin >> n;
	do {
		cin >> Istr;
		while (n--) {
			for (int i = 0; i < (int)Istr.size();) {
				ch = Istr[i];
				for (int j = i; i < (int)Istr.size(); j++) {
					if (Istr[i] == Istr[j]) {
						b++;
					}
					else
					{
						i = j;
						break;
					}
				}
				Ostr += to_string(b);
				Ostr.push_back(ch);
				b = 0;
			}
			Istr.clear();
			Istr = Ostr;
			Ostr.clear();
		}
		cout << Istr << endl;
		cin >> n;
	} while (n != 0);
	return 0;
}