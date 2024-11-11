N,X = map(int,input().split())
L = list(map(int,input().split()))
p = 0
cnt = 1
for l in L:
	p += l
	if p <= X:
		cnt += 1
print(cnt)