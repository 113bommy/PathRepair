l=int(input())
s=input()
k=l//2
ans=int(s)
while k>0:
    if s[k]=='0':
        k=k-1
    else:
        ans=min(ans,int(s[:k])+int(s[k:]))
        break

k=(l//2)+1
while k<l:
    if s[k]=='0':
        k=k+1
    else:
        ans=min(ans,int(s[:k])+int(s[k:]))
        break

print(ans)

