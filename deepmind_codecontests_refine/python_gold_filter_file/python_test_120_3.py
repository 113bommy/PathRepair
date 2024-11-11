def gv(x, y):
    if x<1:
        return 0
    if y==1:
        return (x+1)//2
    cnt = (x // (2*y)) * y
    x %= 2*y
    if x >= y:
        return cnt + x - y + 1
    return cnt
    

for _ in range(int(input())):
    l,r=map(int,input().split())
    if l == r:
        print(0)
        continue
    mxc=0
    for i in range(23):
        cnt = gv(r,2**i) - gv(l-1,2**i)
        mxc=max(mxc,cnt)
    print(r-l+1-mxc)
