for _ in range(int(input())):
    n=int(input())
    alist=list(map(int,input().split()))
    flag=0
    a=alist[0]+alist[1]
    c=0
    for i in range(2,n):
        if(a<=alist[i]):
            c=i+1
            flag=1
            break
            
    if(flag==1):
        print("1","2",c)
    else:
        print("-1")