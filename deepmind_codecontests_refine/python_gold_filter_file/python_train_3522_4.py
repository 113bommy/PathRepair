N = int(input())
T = [list(map(int, input().split())) for k in range(N-1)]

for k in range(N):
	t = 0
	for i in range(k,N-1):
		if t < T[i][1]:
			t = T[i][0]+T[i][1]
		else:
			t += T[i][0]+ (T[i][2]-t%T[i][2])%T[i][2]
	print(t)