a=str(input())
k=0
l=0
if len(a)%2==0:
    s1=(a[:len(a)//2])
    s2=(a[len(a)//2:])
else:
    k=len(a)//2
    s1=a[:k]
    s2=a[k+1:]
s2=s2[::-1]
for i in range(len(s1)):
    if s1[i]!=s2[i]:
        l=l+1
if l==1:
    print("YES")
else:
    if len(a)%2==1 and l==0:
        print("YES")
    else:
        print("NO")
    
