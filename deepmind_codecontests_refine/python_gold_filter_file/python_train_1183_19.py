t=lambda:map(int,input().split())
a,b=t()
g=sorted(list(t()))
print(g[-b],0) if b<=a else print(-1)