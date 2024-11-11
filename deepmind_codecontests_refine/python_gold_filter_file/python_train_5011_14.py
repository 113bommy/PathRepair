n=int(input())
s=list(input())
ans=int()
if n==2:
    if s[0]==s[1]:
        e=set("RGB")
        ans=1
        e.remove(s[0])
        s[1]=e.pop()
elif n>2:
    for i in range(1,n-1):
        k=s[i]
        pr=s[i-1]
        ne=s[i+1]
        e=set("RGB")
        if pr==k:
            ans+=1
            if pr==ne:
                e.remove(k)
                s[i]=e.pop()
            else:
                e.remove(pr)
                e.remove(ne)
                s[i]=e.pop()
    if s[n-1]==s[n-2]:
        e=set("RGB")
        ans+=1
        e.remove(s[n-1])
        s[n-1]=e.pop()
print(ans)
print("".join(s))

