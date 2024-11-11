n=int(input())
t=list(map(int,input().split()))
for i in range(n):
	if t[n-1-i]==1:
		f=n-1-i
		break

for i in range(n):
	if t[n-1-i]==0:
		tt=n-1-i
		break
print(min(f,tt)+1)
exit(0)