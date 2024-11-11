n,p,w,d=map(int,input().split())
temp=0
if p==0:
    print('0','0',n);exit()
for x in range(p//w,max(p//w-100000,-1),-1):
    if (p-x*w)%d==0 and x+(p-x*w)//d<=n:
        temp=1
        y=(p-x*w)//d;break
    elif (p-x*d)%w==0 and x+(p-x*d)//w<=n:
        temp=1;y=x;x=(p-y*d)//w;break

print(x,y,n-x-y) if temp==1 else print('-1')