import sys
n , m = map(int,input().split())
l = list(map(int,input().split()))
l.sort(reverse = True)

left = 1
right = n+1

ans = 10**18 + 1
while left != right:
    mid = (left+right)//2
    #print(mid,left,right)
    din = 0
    kaam = 0
    c = 0
    for i in l:
        if i - din <=0:
            break
        kaam += i - din
        c += 1
        if c == mid:
            c = 0
            din += 1
    if kaam >= m:
        ans = min(ans,mid)
        right = mid
    else:
        left = mid+1

if ans == 10**18+1:
    print(-1)
else:
    print(ans)