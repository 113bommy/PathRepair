n,b = map(int,input().split())
l = list(map(int,input().split()))
t = max(l)
s = 0
k = []
for i in range(n):
	if b < 0:
		print(-1)
		exit()
	b = b - (t-l[i])
	k.append(t-l[i])
if b < 0:
	print(-1)
	exit()

for i in range(len(k)):
	k[i] = k[i] + b/n
for i in k:
	print(i)