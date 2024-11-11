b=list(map(int,input().split()))
k=b[0]+b[1]-1
print(k)
d=[1,1]

print(*d)
if k>1:
    for i in range(1,k):

        if b[0]>b[1]:
            if d[1]<b[1]:
                if d[0]==d[1]:
                    d[0]+=1
                    print(*d)
                elif d[0]>d[1]:
                    d[1]+=1
                    print(*d)
            else:
                d[0]+=1
                print(*d)
        elif b[0]<b[1]:
            if d[0]<b[0]:
                if d[0]==d[1]:
                    d[1]+=1
                    print(*d)
                elif d[1]>d[0]:
                    d[0]+=1
                    print(*d)
            else:
                d[1] += 1
                print(*d)

        else:
            if d[0] == d[1]:
                d[0] += 1
                print(*d)
            elif d[0] > d[1]:
                d[1] += 1
                print(*d)