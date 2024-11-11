n,k=map(int,input().split())
b=list(map(int,input().split()))
s=input()
a=[]
if k==1:
    print(-1)
    exit()
for i in range(n):
    a.append((b[i],s[i]))
a.sort(reverse=True)
i=0
j=0
m1=0
q1=False
q2=False
while i!=k:
    if a[j][1]!='R':
        m1+=a[j][0]
        g=j+0
        if a[j][1]=='W':
            q1=True
        else:
            q2=True
        i+=1
    j+=1
    if j==n and i!=k:
        m1=0
        break
else:
    if not (q1 and q2):
        m1-=a[g][0]
        for i in range(g+1,n):
            if q1 and a[i][1]=='O' or q2 and a[i][1]=='W':
                m1+=a[i][0]
                break
        else:
            m1=0
i=0
j=0
m2=0
q1=False
q2=False
while i!=k:
    if a[j][1]!='W':
        m2+=a[j][0]
        g=j+0
        if a[j][1]=='R':
            q1=True
        else:
            q2=True
        i+=1
    j+=1
    if j==n and i!=k:
        m2=0
        break
else:
    if not (q1 and q2):
        m2-=a[g][0]
        for i in range(g+1,n):
            if q1 and a[i][1]=='O' or q2 and a[i][1]=='R':
                m2+=a[i][0]
                break
        else:
            m2=0
if m1 or m2:
    print(max(m1,m2))
else:
    print(-1)
    
    
    
        
