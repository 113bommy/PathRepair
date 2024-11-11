n=int(input())
l=list(map(int,input().split()))
l.sort()
l=list(set(l))
if len(l)>3:
    print(-1)
else:
    if len(l)==2:
        if (l[1]-l[0])%2==0:
            print((l[1]-l[0])//2)
        else:
            print(l[1]-l[0])
    elif len(l)==3:
        if l[2]-l[1]==l[1]-l[0]:
            print(l[2]-l[1])
        else:
            print(-1)
    else:
        print(0)