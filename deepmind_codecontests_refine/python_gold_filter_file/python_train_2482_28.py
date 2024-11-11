s=input()
t=input()
n=len(s)
m=len(t)
ans=-1
for i in range(n-m+1):
    sum=0
    for j in range(m):
        if s[i+j]==t[j] or s[i+j]=='?':
            sum+=1
    if sum==m:
        ans=i
if ans==-1:
    print('UNRESTORABLE')
else:
    s=s[:ans]+t+s[ans+m:]
    b=s.replace('?','a')
    print(b)