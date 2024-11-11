n,k=map(int,input().split())
l,c=[],[]
for i in range(k):
    x,y=input().split()
    l.append(x)
    c.append(y)
p=''
s=input().split()
for i in s:
    for j in range(k):
        if  l[j]==i:
            if len(l[j])<=len(c[j]):
                p+=l[j]
            else:
                p+=c[j]
    p+=' '                       
print(p)                    