t=int(input())
for i in range(t):
    x, y, n=map(int,input().split())
    print(n-(n-y)%x)