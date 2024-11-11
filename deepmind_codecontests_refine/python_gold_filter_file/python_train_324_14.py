n=int(input())
s=sorted(list(map(int,input().split( ))))
f=[]
z=[]
for i in s:
    if i%2==1:
        f.append(i)
    else:
        z.append(i)
if abs(len(z)-len(f))<=1:
    print(0)
elif len(z)-len(f)>1:
    s=0
    for i in range(0,len(z)-len(f)-1):
        s+=z[i]
    print(s)
else:
    s=0
    for i in range(0,len(f)-len(z)-1):
        s+=f[i]
    print(s)
