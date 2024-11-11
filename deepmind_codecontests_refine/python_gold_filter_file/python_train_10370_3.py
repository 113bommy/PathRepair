n,k=list(map(int,input().strip().split()))
l=list(map(int,input().strip().split()))
d=0
t=0
for i in l:
    if (t+i)<=8 and (t+i)>=k:
        print(d+1)
        break
    elif (t+i)<=8:
        d +=1
        t=0
        k=k-(i+t)
        if k<=0:
            print(d)
            break
    elif (t+i)>8:
        t +=(i-8)
        k=k-8
        d +=1
        if k<=0:
            print(d)
            break
else:
    if k<=0:
        print(n)
    else:
        print("-1")
        
