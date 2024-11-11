n=int(input())
a=list(map(str,input().split()))
z=1
s=0
k=str(1)
qwerty=['2','3','4','5','6','7','8','9']
for i in range(n):
    q=0
    p=0
    for j in range(len(a[i])):

        if a[i][j] in qwerty:
            q=1
        elif a[i][j] == '1':
            p=p+1
    if p>1:
        q=1
    else:
        q=q
    if a[i]=='0':
        z=0
    elif q==0:
        s=s+len(str(a[i]))-1
    else:
        k=a[i]
y=k+'0'*s
if z==1:
    print(y)
else:
    print('0')
