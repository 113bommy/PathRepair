
#include "stdio.h"
#include <vector>

using namespace std;

int main()
{
	int n, a, v;
	vector<int> vec;

	scanf_s("%d", &n);

	int ni = 0;

	while (ni < n)
	{
		scanf_s("%d", &a);
		if (a == 0) {
			scanf_s("%d", &v);
			vec.push_back(v);
		}
		else if (a == 1) {
			scanf_s("%d", &v);
			printf("%d\n", vec[v]);
		}
		else {
			vec.pop_back();
		}
		ni++;
	}

    return 0;
}
