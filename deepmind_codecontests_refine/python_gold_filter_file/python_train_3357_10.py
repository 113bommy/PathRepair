for _ in range(int(input())):
    n,k=map(int,input().split()) #4 12
    val=n-1 #3
    x=val #3
    cnt=1
    if k%val==0:
        cnt=k//val
    else:
        cnt=k//val+1
    x*=cnt
    newval = n * cnt
    if x==k:
        print(newval-1)
    else:
        xval=newval-val #10
        xval+=((k%val)-1)
        print(xval)


