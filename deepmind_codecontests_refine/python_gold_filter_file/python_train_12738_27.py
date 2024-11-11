n=int(input())
if n%2!=0:print(-1)
else:print(*[x for x in range(1,n+1)][::-1])