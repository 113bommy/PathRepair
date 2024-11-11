n,a,b = map(int,input().split())
ans = a*(n//(a+b)) + min(n%(a+b),a)
print(ans)