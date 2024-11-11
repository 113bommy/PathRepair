t = int(input())
for i in range(t):
    x,y,n = [int(x) for x in input().split()]
    h = int(n-(n%x)+y)
    l= int(n-(n%x)-(x-y))
    if h>n:
        print(l)
    else:
        print(h)
            
            
