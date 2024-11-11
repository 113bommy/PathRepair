n=int(input())
s=input()
ans=0
for i in range(1000):
    i=str(i).zfill(3)
    a=0
    for c in s:
        if c==i[a]:
            a+=1
        if a==3:
            ans+=1
            break
print(ans)