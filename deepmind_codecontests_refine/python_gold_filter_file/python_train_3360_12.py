for w in range(int(input())):
    n,x=tuple(map(int,input().split()))
    a=list(map(int,input().split()))
    b=[]
    count=0
    for i in range(n):
        b.append(a[i]-x)
        if(a[i]==x):
            count+=1
    if(count==n):
        print(0)
    elif(count>=1 or sum(b)==0):
        print(1)
    else:
        print(2)