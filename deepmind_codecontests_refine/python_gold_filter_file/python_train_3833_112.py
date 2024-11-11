a,b,c = map(int,input().split())
ans = b + min(c,a+b+1)
print(ans)