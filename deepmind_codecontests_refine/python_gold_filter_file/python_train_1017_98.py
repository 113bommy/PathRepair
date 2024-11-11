n,k,s=map(int,input().split())
ans = (str(s) + ' ')*k + (str(s-1 or 8) + ' ')*(n-k)
print(ans[:-1])