n=int(input())
a=input()
w=a.count('W')
b=n-w
if w%2==1 and b%2==1:
    print(-1)
else:
    x='W' if w%2==0 else 'B'
    c=0
    p=0
    ans=[]
    for i in range(n):
        if (a[i]==x and p==0) or (a[i]!=x and p==1):
            c+=1
            p=1
            ans.append(i+1)
        else:
            p=0
    print(c)
    print(*ans)
        