h,d=map(int,input().strip().split(" "))
l=list(map(int,input().strip().split(" ")))
s=0; m=0; ans=0
for c in l:
    s+=c
    m=min(m,s)
#print((h+m,s))
if h+m>0 and s>=0:
    print(-1);exit(0)
s=abs(s)
if s!=0:ans=(max(0,h+m)+s-1)//s #important step to add max(h+m,0)
h-=ans*s
ans*=d
for i in l:
    if h<=0:
        break
    h+=i
    ans+=1
print(ans)
