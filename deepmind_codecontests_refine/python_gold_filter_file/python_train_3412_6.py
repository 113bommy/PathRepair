K = int(input())
L,r = K*9 if K%7 else K*9//7, 10
for i in range(1,L+1):
	r %= L
	if r == 1:
		print(i)
		exit()
	r *= 10
print(-1)