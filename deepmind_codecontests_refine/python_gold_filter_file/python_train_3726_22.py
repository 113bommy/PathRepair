N=int(input())
X,Y=[0]*N,[0]*N
for i in range(N):
    X[i],Y[i]=map(int,input().split())

def check(a,b,r):
    if r<0:r=0
    res=[0,0,0]
    flg=True
    for i in range(N):
        tmp=(X[i]-a)**2+(Y[i]-b)**2
        if tmp>r**2:
            flg=False
        if tmp>res[0]:
            res=[tmp,X[i],Y[i]]
    res[0]=flg
    return res

x_ave,y_ave=sum(X)/N,sum(Y)/N
MIN=10**(-12)
r=1500
r_diff=r/2
k=0.5
d=999/1000


#print(x_ave,y_ave)
while r_diff>MIN:
    tmpres = check(x_ave,y_ave,r)
    #print(r,x_ave,y_ave)
    if tmpres[0]:
        r-=r_diff
    else:
        r+=r_diff
    x_ave+=(tmpres[1]-x_ave)*k
    y_ave+=(tmpres[2]-y_ave)*k
    r_diff=r_diff*d
    k=k*d

print(r)