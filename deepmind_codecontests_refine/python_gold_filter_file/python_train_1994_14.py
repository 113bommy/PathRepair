n = list(map(int, input().split()))
a = list(set(map(int, input().split())))
a.sort()

sz = len(a)
if(sz == 1) :
    print(0)
elif(sz == 2) :
    if((a[1] - a[0]) % 2 == 0) :
        print(int((a[1] - a[0]) / 2))
    else :
        print(a[1] - a[0])
elif(sz > 3) :
    print(-1)
else :
    if(a[2] - a[0] != (a[1] - a[0]) * 2) :
        print(-1)
    else :
        print(a[1] - a[0])