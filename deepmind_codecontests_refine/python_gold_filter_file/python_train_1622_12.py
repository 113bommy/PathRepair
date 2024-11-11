n=int(input())
a=[int(i) for i in input().split()]
if(len(a)-a.count(0)<1):
    print("NO")
elif(len(a)-a.count(0)==1):
    print("YES\n1\n1",len(a))
else:
    print("YES")
    x=0
    b=[0]
    for i in range(n):
        if(a[i]!=0):
            x+=1
            b.append(i+1)
    print(x)
    for i in range(1,len(b)-1):
        print(b[i-1]+1,b[i])
    print(b[len(b)-2]+1,n)