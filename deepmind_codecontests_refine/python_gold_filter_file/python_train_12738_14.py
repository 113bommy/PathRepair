n=int(input())
l1=[]
l2=[]
count=1
if n%2!=0:
    print(-1)
else:
    for i in range(n,0,-1):
        if count!=i:
            l2.append(i)
        else:
            l1.append(i)
        count+=1
    new=l2+l1
    print(*new)