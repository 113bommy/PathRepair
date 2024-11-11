n=int(input())
l=[]
ans=0
for i in range(n):
    s=input()
    l.append(s)
x="abcdefghijklmnopqrstuvwxyz"
for i in range(26):
    for j in range(i+1,26):
        c=0
        for s in l:
            l1=len(s)
            if(s.count(x[i])+s.count(x[j])==l1):
                c+=l1
        ans=max(ans,c)

print(ans)

