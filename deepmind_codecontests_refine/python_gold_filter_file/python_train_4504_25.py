R=lambda:map(int,input().split())
t,=R()
for _ in[0]*t:n,m=R();b=([2]+[3]*(m-2)+[2])*2;b[m:m]=([3]+[4]*(m-2)+[3])*(n-2);print(*(['YES']+b,['NO'])[any([x>y
for i in range(n)for x,y in zip(R(),b[i*m:])])])