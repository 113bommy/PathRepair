t=int(input())
while t>0:
    a,b,k=input().split()
    d=int(a)
    c=int(b)
    p=int(k)
    max1=0
    if(d==0 and k==0 and p==0):
        max1=0
    elif((d>=1 and p==0 and c==0) or (d==0 and p>=1 and c==0) or (d==0 and p==0 and c>=1)):
        max1=1
    elif((d==0 and p==1 and c>=1) or (d==1 and p==0 and c>=1) or (d==1 and p>=1 and c==0)  or (d==0 and p>=1 and c==1) or (d>=1 and p==1 and c==0) or (d>=1 and p==0 and c==1)):
        max1=2
    elif((d==1 and p==1 and c>=1) or (d==1 and c==1 and p>=1) or (c==1 and p==1 and d>=1) or (d==0 and p>=2 and c>=2) or (p==0 and d>=2 and c>=2) or (c==0 and p>=2 and d>=2)):
        max1=3
    elif((d==1 and p>=2 and c>=2) or (p==1 and d>=2 and c>=2) or (c==1 and p>=2 and d>=2) or(d==2 and p==2 and c==2)):
        max1=4
    elif((d==2 and p==2 and c>=3) or (c==2 and p==2 and d>=3) or (d==2 and c==2 and p>=3) or (d>=3 and p>=3 and c==2) or (d>=3 and c>=3 and p==2) or  (c>=3 and p>=3 and d==2)  ):
        max1=5
    elif ((d==3 and p>=3 and c>=3) or (p==3 and d>=3 and c>=3) or (c==3 and p>=3 and d>=3)):
        max1=6
    elif((d>=4 and p>=4 and c>=4)):
        max1=7
    print(max1)
    t=t-1