n = int(input())
if(n%2==1):
    print(-1)
else:
    e = 2
    o = 1
    for i in range(n):
        if(i%2==0):
            print(e,end=' ')
            e+=2
        else:
            print(o,end=' ')
            o+=2
