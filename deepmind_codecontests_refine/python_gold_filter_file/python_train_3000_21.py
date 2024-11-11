#python3.4
import math
def inpul(): return list(map(int, input().split()))

N, M = inpul()
A = inpul()

c = [0,2,5,5,4,5,6,3,7,6]
f = [-1]*10010

f[0] = 0
for i in range(1, N+1):
	for x in A:
		if i-c[x] >= 0:
			f[i] = max(f[i], f[i-c[x]]*10+x)
print(f[N])
