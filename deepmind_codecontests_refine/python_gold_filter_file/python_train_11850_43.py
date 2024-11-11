import math
n, m = map(int, input().split())
X=1
for i in range(1,32000):
	if m%i==0:
		if i*n<=m:
			X=max(X, i)
		if (m//i)*n<=m:
			X=max(X, m//i)
print(X)