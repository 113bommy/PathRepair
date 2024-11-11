s=input()
sol=[]
a=[0 for _ in range(len(s))]
a[0]=s[0]
for i in range(1,len(s)):
    t=s[i]
    a[i]=min(a[i-1],s[i])
print('Mike')
for i in range(1,len(s)):
    if s[i]>a[i]:
        print('Ann')
    else:
        print('Mike')
        
    