a,b=input().split()
d='0'
y,z=len(a),len(b)
for i in range(y):
    d=max(d,a[i])
for i in range(z):
    d=max(d,b[i])
d=int(d)+1
c=0
for i in range(y):
    c+=int(a[y-1-i])*(d**i)
for i in range(z):
    c+=int(b[z-1-i])*(d**i)
e=0
while c>0:
    e+=1
    c//=d
print(e)