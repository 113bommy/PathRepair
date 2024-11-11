N = int(input())
A = list(map(int, input().split()))
flag = True
for i in range(0, N):
	for j in range(0, N):
		if i != j:
			for k in range(0, N):
				if j != k:
					if A[i] == A[j] + A[k]:
						flag = False
						print(str(i+1)+' '+str(j+1)+' '+str(k+1))
						break
		if not flag: break
	if not flag: break
if flag: print(-1)