k=int(input())
s=input().strip()
n=len(s)
l=[0]*26
fg=0
ans=[]
for i in s:
    l[ord(i)-97]+=1
for i in range(0,26):
    if (l[i]!=0)and((l[i]<k) or (l[i]%k)!=0):
        fg=1
        break
if fg==1:print(-1)
else:
    for i in range(0,26):
        b=l[i]//k
        for j in range(0,b):
            ans.append(chr(i+97))
    ans="".join(str(a) for a in ans)
    print(ans*k)