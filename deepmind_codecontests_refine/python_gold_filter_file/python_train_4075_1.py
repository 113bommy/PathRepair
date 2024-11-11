n=int(input())
a=[int(s) for s in input().split()]
x=max(a)
a.sort()
k=[-1]
a.pop()
c=y=max(a)
for i in range(len(a)):
    if x%a[i]==0 and (int(a[i] in k)==0):
        k.append(a[i])
        a[i]=-1
if max(k)==x:
    y=x
else:
    y=max(a)
print(x,y)