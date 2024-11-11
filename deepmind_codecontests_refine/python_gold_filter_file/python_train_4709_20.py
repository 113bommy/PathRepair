n=input()
a=list(n)
m=0
q=0
for i in range(len(a)):
    a[i]=ord(a[i])
if a[0]>96:
    for i in range(1,len(a)):
        if a[i]>96:
            m=m+1
    if m==0:
        for i in range(1,len(a)):
            a[i]=a[i]+32
        a[0]=a[0]-32
else:
    for i in range(1,len(a)):
        if a[i]>96:
            q=q+1
    if q==0:
        for i in range(len(a)):
            a[i]=a[i]+32
for i in range(len(a)):
    a[i]=chr(a[i])
print(''.join(a))
    
