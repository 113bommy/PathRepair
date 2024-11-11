n, k = map(int,input().split())
if k is 0:
    for i in range(1,n+1):
        if i is n:
            print (i,end="")
        else:
            print (i,end=" ")
    
elif k is n-1:
    for i in range(n,0,-1):
        if i is 1:
            print (i,end="")
        else:
            print (i,end=" ")

else:
    for i in range(n,n-k,-1):
        print (i,end = " ")
    for i in range(1,n-k+1):
        if i is n-k:
            print (i,end="")
        else:
            print (i,end=" ")