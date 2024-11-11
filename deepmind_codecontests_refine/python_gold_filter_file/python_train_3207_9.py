s=input()
r=[0]
ans=[0]*len(s)
for i in range(len(s)-1):
    if s[i]!=s[i+1]:
        r.append(i+1)
r.append(len(s))

for i in range(len(r)-1):
    if i%2==1:
        ans[r[i]]=(r[i]-r[i-1])//2+(r[i+1]-r[i]+1)//2
        ans[r[i]-1]=(r[i+1]-r[i])//2+(r[i]-r[i-1]+1)//2
print(*ans)
