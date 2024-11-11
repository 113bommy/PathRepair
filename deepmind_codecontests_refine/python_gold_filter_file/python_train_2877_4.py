n=int(input())
l=[0]
s=0
l.extend([int(i)-1 for i in input().split()])
m=[int(i) for i in input().split()]
cv=[0]*n
if m[0]!=0:
    cv[0]=m[0]
    s+=1
for i in range(n):
    if m[i]!=cv[l[i]]:
        cv[i]=m[i]
        s+=1
    else:
        cv[i]=cv[l[i]]  
print(s)