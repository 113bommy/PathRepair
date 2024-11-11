#include <iostream>

int main()
{
	for (int i=1, a;; ++i) {
		std::cin >> a;
		if (!a) break;
		std::cout << "Case " << i << ": " << a << '\n';
	}
}