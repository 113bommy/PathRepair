from collections import Counter
t=int(input())
for z in range(t):
    n=int(input())
    a=[int(q)for q in input().split()]
    d=Counter(a)
    index=0
    ans=True
    for i in d:
        if d[i]==1:
            index=a.index(i)
            break
    if len(d)==1:
        print("NO")
        ans=False
    else:
        print("YES")
    if ans:
        for j in range(n):
            if j!=index and a[j]!=a[index]:
                print(index+1,j+1)
                rest=j
        for k in range(n):
            if a[k]==a[index] and k!=index:
                print(rest+1,k+1)
    
            
    
        
