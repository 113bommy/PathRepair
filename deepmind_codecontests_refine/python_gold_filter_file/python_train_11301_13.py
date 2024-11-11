l1,r1,l2,r2,k=map(int,input().split())
p=max(l1,l2)
q=min(r1,r2);m=q-p+1
if k>=p and k<=q: m-=1
print(m if q>=p else '0')