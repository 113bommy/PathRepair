import sys
n=int(input())
s=list(map(int,input().split()))
if n==1:
    print(0)
    sys.exit()
if n==2:
    print(0)
    sys.exit()
s1=s.copy()
m=n+3
x1=2
s=s1.copy()
s[1]+=1 ;s[0]+=1
dif1=s[1]-s[0]
t1=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif1)>1:
        t1=False
        x1=n+100
        break
    else:
        if s[i+1]-s[i]-dif1==-1:
            x1+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif1==1:
            s[i+1]-=1
            x1+=1
x2=2
s=s1.copy()
s[1]+=1 ;s[0]-=1
dif2=s[1]-s[0]
t2=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif2)>1:
        t2=False
        x2=n+100
        break
    else:
        if s[i+1]-s[i]-dif2==-1:
            x2+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif2==1:
            s[i+1]-=1
            x2+=1
x3=1
s=s1.copy()
s[1]+=1;
dif3=s[1]-s[0]
t3=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif3)>1:
        t3=False
        x3=n+100
        break
    else:
        if s[i+1]-s[i]-dif3==-1:
            x3+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif3==1:
            s[i+1]-=1
            x3+=1
x4=2
s=s1.copy()
s[1]-=1 ;s[0]+=1
dif4=s[1]-s[0]
t4=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif4)>1:
        t4=False
        x4=n+100
        break
    else:
        if s[i+1]-s[i]-dif4==-1:
            x4+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif4==1:
            s[i+1]-=1
            x4+=1
x5=2
s=s1.copy()
s[1]-=1 ;s[0]-=1
dif5=s[1]-s[0]
t5=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif5)>1:
        t5=False
        x5=n+100
        break
    else:
        if s[i+1]-s[i]-dif5==-1:
            x5+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif5==1:
            s[i+1]-=1
            x5+=1
x6=1
s=s1.copy()
s[1]-=1 ;
dif6=s[1]-s[0]
t6=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif6)>1:
        t6=False
        x6=n+100
        break
    else:
        if s[i+1]-s[i]-dif6==-1:
            x6+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif6==1:
            s[i+1]-=1
            x6+=1
x7=1
s=s1.copy()
s[0]+=1
dif7=s[1]-s[0]
t7=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif7)>1:
        t7=False
        x7=n+100
        break
    else:
        if s[i+1]-s[i]-dif7==-1:
            x7+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif7==1:
            s[i+1]-=1
            x7+=1
x8=1
s=s1.copy()
s[0]-=1
dif8=s[1]-s[0]
t8=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif8)>1:
        t8=False
        x8=n+100
        break
    else:
        if s[i+1]-s[i]-dif8==-1:
            x8+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif8==1:
            s[i+1]-=1
            x8+=1
x9=0
s=s1.copy()
dif9=s[1]-s[0]
t9=True
for i in range(1,n-1):
    if abs(s[i+1]-s[i]-dif9)>1:
        t9=False
        x9=n+100
        break
    else:
        if s[i+1]-s[i]-dif9==-1:
            x9+=1
            s[i+1]+=1
        elif s[i+1]-s[i]-dif9==1:
            s[i+1]-=1
            x9+=1
if t1 or t2 or t3 or t4 or t5 or t6 or t7 or t8 or t9:
    print(min(x1,x2,x3,x4,x5,x6,x7,x8,x9))
else:
    print(-1)
