a,b,n = map(int,input().split())
i = min(b-1,n)
ans = a*i//b - a*(i//b)
print(ans)