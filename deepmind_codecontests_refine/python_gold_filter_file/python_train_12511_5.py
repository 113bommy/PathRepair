n,k=map(int,input().split())
 
if k==(n*(n+1))//2:
    print(0)
else:
    left=0
    right=n
    while left<right:
        mid=(left+right)//2
        candies=(mid*(mid+1))//2
        if candies + mid < k + n:
            left=mid+1
        else:
            right=mid
    print(n-left)
            
            