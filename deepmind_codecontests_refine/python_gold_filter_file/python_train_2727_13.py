def gridfill(r,c):
    empty=0
    for i in range(len(r)):
        for j in range(len(c)):
            if j>r[i] and i>c[j]:
                empty+=1
            if i<c[j] and j==r[i]:
                return 0
            if i==c[j] and j<r[i]:
                return 0
            
    if empty>0:
        return (2**empty)%1000000007
    else:
        return 1

def io():
    h,w = map(int,input().split())
    r = list(map(int,input().split()))
    c = list(map(int,input().split()))
    print(gridfill(r,c))

io()
