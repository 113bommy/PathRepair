a,b=map(int,input().split())
n,m=map(int,input().split())
t1,t2=map(int,input().split(':'))
h=t1-5
t2=t2
st=t2+h*60
fin=st+b
now=0
ans=0
while now<fin and now<1140:
    if now+m>st:
        ans+=1
    now+=n
print(ans)