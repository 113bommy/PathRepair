t = int(input())
for i in range(t):
    n,x,y = list(map(int,input().split()))
    if x+y < n+1:
        minimum = 1
    elif n+1 <= x+y:
        minimum = min(x+y-n+1,n)
    print(minimum,min(x+y-1,n))