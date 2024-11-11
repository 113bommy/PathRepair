t = int(input())
while t:
    n,m = map(int,input().split())
    if n == 1:
        print(0)
    elif n == 2:
        print(m)
    else:
        print (m<<1)
    t -= 1
