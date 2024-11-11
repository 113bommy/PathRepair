n,k=map(int,input().split())
p = list(map(int, input().split()))

ans = []
ans.append(p[0])
for i in range(1,n):
    if len(ans) < k and p[i] not in ans:
        ans.insert(0,p[i])
    elif len(ans) == k and p[i] not in ans:
        ans[1:] = ans[:-1]
        ans[0] = p[i]
print (len(ans))
print (*ans)