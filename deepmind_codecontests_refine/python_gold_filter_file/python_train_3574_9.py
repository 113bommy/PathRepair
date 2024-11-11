m,n=map(int,input().split())
l=list(map(int,input().split()))
if n not in l:
    l.append(n)
    ans=1
else:
    ans=0    
l.sort()
if l[(len(l)+1)//2-1]==n:
    print(ans)
elif l[(len(l)+1)//2-1]<n:
    while l[(len(l)+1)//2-1]<n:
        l.insert(-1,10**5+1)
        ans+=1
    print(ans)
elif l[(len(l)+1)//2-1]>n:
    while l[(len(l)+1)//2-1]>n:
        l.insert(0,0)
        ans+=1
    print(ans)
