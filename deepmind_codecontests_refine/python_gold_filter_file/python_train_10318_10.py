n=int(input())
a=list(map(int,input().split()))
d={}
m=10000000000
count1=0
p=0
t=0
for i in a:
    d[i]=d.get(i,0)+1
    if d[i]<m:
        m=d[i]
        
if m>=2:
    print('YES')
    print('A'*n)
    
else:
    s='A'*n
    for i in range(n):
        if d[a[i]]==1 and count1%2==0:
            s=s[:i]+'B'+s[i+1:]
            count1+=1
        elif d[a[i]]==1:
            count1+=1
    if count1%2==0:
        print('YES')
        print(s)
    else:
        for i in range(n):
            if d[a[i]]>2:
                k=a[i]
                s=s[:i]+'A'+s[i+1:]
                t=1
                break
        if t==1:
            for p in range(i+1,n):
                if a[p]==k:
                    s=s[:p]+'B'+s[p+1:]
            print('YES')
            print(s)
        if t==0:
            print('NO')
    