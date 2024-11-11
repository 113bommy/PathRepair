n,m = map(int,input().split())
arr = list(map(int,input().split()))
if sum(arr)<n:
    print(-1)
    exit()
ans = []

p = n+1
for c in arr[::-1]:
    p  = min(p-1,n+1-c)
    ans.append(p)
ans = ans[::-1]
if ans[0]<1:
    print(-1)
    exit()
if ans[0]>1:
    pos = 1
    for i,c in enumerate(arr):
        ans[i] = min(ans[i],pos)
        pos = pos+c
print(*ans)