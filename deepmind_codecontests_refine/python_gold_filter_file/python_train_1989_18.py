n=int(input())
m=int(input())
a=[]
for i in range(n):
    a.append(int(input()))
a.sort()
s=0
mah=m+a[-1]
for i in range(len(a)-1):
    s+=a[-1]-a[i]
if m>s:
    mi=(m-s)//n
    if (m-s)%n!=0:
        mi+=1
    mi+=a[-1]
    print(mi, mah)
else:
    print(a[-1],mah)
    
