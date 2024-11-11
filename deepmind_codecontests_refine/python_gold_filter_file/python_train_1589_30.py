t=int(input())
for _ in range(t):
    x,y,n=[int(i) for i in input().split()]
    print(n-((n-y)%x))