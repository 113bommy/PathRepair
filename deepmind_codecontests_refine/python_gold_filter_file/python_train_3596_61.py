try:
    n,x=list(map(int,input().split()))
    i=0
    cnt=0
    while i<n:
        l=list(map(str,input().split()))
        if l[0]=="+":
            x=x+int(l[1])
        else:
            if x>=int(l[1]):
                x=x-int(l[1])
            else:
                cnt+=1
        i+=1
    print(x,cnt)
    
except:
    pass
