n,p,w,d=map(int,input().split())
for i in range(w):
    if(p-i*d>=0 and (p-i*d)%w==0 and (p-i*d)//w+i<=n):
        print((p-i*d)//w,i,n-(p-i*d)//w-i)
        break
else:
    print(-1)
