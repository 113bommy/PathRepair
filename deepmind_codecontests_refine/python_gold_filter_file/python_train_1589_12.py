t = int(input())
for i in range(t):
    x,y,n = map(int,input().split())
    i = n%x
    if(i<y):
        n-= i
        n -= abs(x-y)
        print(n)
    elif(y<i):
        n-= abs(i-y)
        print(n)
    else:
        print(n)