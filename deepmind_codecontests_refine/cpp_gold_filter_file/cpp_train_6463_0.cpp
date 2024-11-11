
#include "stdio.h"
#include <vector>

using namespace std;

int main()
{
	int n, a, v;
	vector<int> vec;

	scanf("%d", &n);

	int ni = 0;

	while (ni < n)
	{
		scanf("%d", &a);
		if (a == 0) {
			scanf("%d", &v);
			vec.push_back(v);
		}
		else if (a == 1) {
			scanf("%d", &v);
			printf("%d\n", vec[v]);
		}
		else {
			vec.pop_back();
		}
		ni++;
	}

    return 0;
}
