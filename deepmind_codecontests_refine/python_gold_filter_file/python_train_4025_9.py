h,m=map(int,input().split())
H,D,C,N=map(int,input().split())
def noofbuns(hun,n):
    if hun%n==0:
        return round(hun/n,4)
    else:
        return round(hun//n+1,4)
if h*60+m>1200:
    print(round(noofbuns(H,N)*C*0.8,4))
else:
    a=20*60-h*60-m
    ch=H+a*D
    cost1=round(noofbuns(ch,N)*C*0.8,4)
    cost2=round(noofbuns(H,N)*C,4)
    print(round(min(cost1,cost2),4))