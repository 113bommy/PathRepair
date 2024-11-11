r,c,k  = [int(tmp) for tmp in input().split()]
ans = 0
for i in range(1, k+1) :
	k = r - (4*(i-1))
	l = c - (4*(i-1))
	ans = ans + 2*k + 2*l - 4
print(ans)