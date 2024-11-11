s = input().split()
a = s[0:2]
b = s[2:4]
for i in range(2):
    a[i]=int(a[i])
    b[i]=int(b[i])
if a[0]-b[0]==0:
    r=abs(int(a[1]-b[1]))
    print(a[0]+r,a[1],b[0]+r,b[1])
elif a[1]-b[1]==0:
    r=abs(int(a[0]-b[0]))
    print(a[0],a[1]+r,b[0],b[1]+r)
elif abs(a[0]-b[0])==abs(a[1]-b[1]):
    print(a[0],b[1],b[0],a[1])
else:
    print(-1)
