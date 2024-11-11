n0,n1=map(int,input().split(" "))
if(n0>n1+1 or n1>2*(n0+1)):
    print(-1)
else:
    if(n0>n1):
        li = ['01']*(n0-1)
        li.append('0')
        print("".join(li))
    else:
        if(n1<=2*n0):
            li = ['110']*(n1-n0)
            li2 = ['10']*(2*n0-n1)
            li+=li2
            print("".join(li))
        else:
            li = ['110']*n0
            li2 = ['1']*(n1-2*n0)
            li+=li2
            print("".join(li))