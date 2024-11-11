n=int(input())
a=list(map(int,input().split()))
cnt=1
for i in range(n):
	if a[i]==cnt:
		cnt+=1

if cnt == 1:
	print(-1)
else:
	print(n-cnt+1)