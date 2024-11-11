x,y,z,t=[int(i) for i in input().split()]
c=0
m0=2*x
for i in range(m0,x-1,-1):
    m1=min(i-1,2*y)
    m1_=max(2*t,y-1)
    judge=0
    for j in range(m1,m1_,-1):
        m2=min(j-1,2*z,2*t)
        m2_=max(z-1,t-1)
        flag=0
        for k in range(m2,m2_,-1):
            print(i)
            print(j)
            print(k)
            c=1
            flag=1
            break
        if flag==1:
            judge=1
            break
    if judge==1:
        break         
if c==0:
    print(-1)
                
        
    
