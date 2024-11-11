
for _ in range(int(input())):
    n,h=map(int,input().split())
    a=list(map(int,input().split()))
    a.append(10**19)
    left,right=0,10**18
    while right-left>1:
        m=(right+left)//2
        ans=0
        for i in range(n):
            ans+=min(a[i+1]-a[i],m)
        #print(left,right)
        if ans<h:
            left=m
        else:
            right=m
    print(right)
#3 4 .. 25 ..64..k..1337..k
#2*k+64-3=1000
#1000-64+3=939
