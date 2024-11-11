t = int(input())
for i in range(t):
    l = list(map(int,input().split()))
    s,e=l[0],l[1]

    if s==e:
        if s%2==0:
            print(s)
        else:
            print(-e)
    elif s+1==e:
        if s%2==0:
            print(-1)
        else:
            print(1)
    else:
        if (e-s+1)%2==0:
            if s%2==0:
                print(-((e-s+1)//2))
            else:
                print(((e-s+1)//2))
        else:
            if s%2==0:
                print(-((e-s)//2)+e)
            else:
                print((e-s)//2-e)
