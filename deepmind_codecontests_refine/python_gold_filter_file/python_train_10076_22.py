n=int(input())
p=list(map(int,input().split()))
a=p[0]
cnt=1
for i in range(1,n):
	if p[i]<a:
		cnt+=1
		a=p[i]
print(cnt)
