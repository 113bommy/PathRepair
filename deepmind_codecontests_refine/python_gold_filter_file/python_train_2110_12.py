t=int(input())
for i in range(t):
    n=int(input())
    a=[int(i) for i in range(1,n+1)]
    print(*a[::-1])