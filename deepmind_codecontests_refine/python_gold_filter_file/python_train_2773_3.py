def f(l,x):
    tx  = l[0]*60+l[1]
    c   = 0
    while True:
        if (tx%60)%10==7 or ((tx//60)%10==7):
            return c
        tx -= x
        c  += 1
        if tx<0:
            tx += 1440  #60*24

x  = int(input())
l  = list(map(int,input().split()))
print(f(l,x))

