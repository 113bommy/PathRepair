n, t = map(int, input().split())
if n==1 and t==10:
    print(-1)
elif t==10:
    print(10**(n-1))
else:
    print(t*(10**(n-1)))