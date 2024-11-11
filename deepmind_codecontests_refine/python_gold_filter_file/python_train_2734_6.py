# your code goes here
t=int(input())
while t>0:
    n=int(input())
    ar=list(map(int,input().split()))
    if len(set(ar))==1:
        print("YES")
    else:
        yep=1
        temp=list(set(ar))
        temp.sort()
        for i in range (0,len(temp)-1):
            if (abs(temp[i]-temp[i+1])!=1):
                yep=0
                break
        if yep==1:
            print("YES")
        else:
            print("NO")
    t-=1
    