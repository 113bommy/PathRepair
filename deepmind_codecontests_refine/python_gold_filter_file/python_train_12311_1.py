def solve():
    n = list(map(int,input().split(" ")))
    a = n[0]
    b = n[1]
    c = n[2]
    if a >= c:
        print(-1,end=" ")
    else:
        print(1,end=" ")
    if (c >= a*b):
        print(-1)
    else:
        print(b)
    
    
t = int(input())
for i in range(t):
    solve()