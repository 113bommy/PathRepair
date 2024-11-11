n,s=map(int,input().split())
if s<n*2:
    print("NO")
else:
    ans=[2 for i in range(n)]
    ans[0]=s-2*(n-1)
    print("YES")
    print(*ans)
    print(1)
