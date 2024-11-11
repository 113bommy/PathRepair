S = sorted
M = lambda : map(int,input().split())
m = int(input())
a = list(M())
max_seg = 2
ans = 2
for i in range(2,m):
	if a[i]==(a[i-1]+a[i-2]):
		max_seg +=1
		ans = max(max_seg,ans)
	else:
		max_seg = 2 
print(min(ans,len(a)))

   