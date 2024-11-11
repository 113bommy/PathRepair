n,a,b = map(int,input().split())
ans = (n//(a+b))*a + min(a,n%(a+b))
print(ans)