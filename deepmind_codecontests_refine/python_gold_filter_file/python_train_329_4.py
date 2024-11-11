n,p,w,d=[int(x) for x in input().split()]
for i in range(w):
    x=i*d
    if p-x>=0 and (p-x)%w==0 and i+(p-x)//w<=n:
        print((p-x)//w,i,n-i-(p-x)//w)
        break
else:
    print(-1)
