def bada(ls,num,ln):
    i=0
    h=ln-1
    res=ln
    while(i<=h):
        m=(i+h)//2
        if ls[m]>num:
            res=m
            h=m-1
        else:
            i=m+1
    return res
#print(bada([1,2,3,4,7,9,10],5,7))
g={}
l={}
lg=0
n=int(input())
a=list(map(int,input().split()))
b=list(map(int,input().split()))
neg=[]
pos=[]
z_c=0
for i in range(n):
    x=a[i]-b[i]
    if x>0:
        pos.append(x)
    elif x==0:
        z_c+=1
    else:
        neg.append(x)

ln_pos=len(pos)
count=ln_pos*z_c+((ln_pos-1)*ln_pos)//2
pos=sorted(pos)

for num in neg:
    count+=ln_pos-bada(pos,abs(num),ln_pos)

            
print(count)
#print(g)
#print(l)

