a=list(input().split())
n=int(a[0])
k=int(a[1])
s=input()

vv=list()
vc=list()

for i in s:
    if i not in vv:
        vv.append(i)
        vc.append(s.count(i))
vc.sort()
sum=0
for i in range(len(vc)-1,-1,-1):
    if vc[i]<k:
        sum+=(vc[i]**2)
        k-=vc[i]
    else:
        sum+=(k**2)
        break
print(sum)
    
        

    