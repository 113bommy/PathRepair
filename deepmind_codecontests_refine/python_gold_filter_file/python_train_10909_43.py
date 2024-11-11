n=int(input())
s=list(input())
ans=0

for i in range(1000):
    num=list(str(i).zfill(3))
    k=0
    for j in range(n):
        if num[k]==s[j]:
            k+=1
            if k==3:
                break
    if k==3:
        ans+=1

print(ans)
    
    