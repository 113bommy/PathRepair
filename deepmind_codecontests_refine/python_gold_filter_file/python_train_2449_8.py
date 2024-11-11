f=lambda:map(int,input().split())
dl,dr=f()
ml,mr=f()

def chk(d,m):
    return d-2<m and m<2*d+3

if chk(dl,mr) or chk(dr,ml):
    print("YES")
else:
    print("NO")
