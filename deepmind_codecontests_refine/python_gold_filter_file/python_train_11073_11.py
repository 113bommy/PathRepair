n=int(input())
if n<=2:
    print(-1)
else:
    print(*[n-x for x in range(n)])