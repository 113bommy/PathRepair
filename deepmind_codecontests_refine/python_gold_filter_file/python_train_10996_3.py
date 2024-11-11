n = int(input())
m = 2*n-1
w = len(str(m+1))-1
ans = 0
for i in range(10):
	v = (i+1)*10**w - 1
	if 0 < v <= m:
		ans += (v-1)//2
		if v > n: ans -= v-n-1
print(ans)