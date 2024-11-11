n,m=(map(int, input().split()))
l=[]
s=[]
r=0
for i in range(n):
    l=(list(map(int, input().split())))
    if l[0]==0:
        r+=1
    else :
        s.append(set(l[1:]))
i=0

while i < len(s):
    for j in s[i+1:]:
        if s[i]&j:
            s[i]|=j
            s.remove(j)
            break;
    else:
            i+=1
print(max(0, len(s)-1+r,r))
