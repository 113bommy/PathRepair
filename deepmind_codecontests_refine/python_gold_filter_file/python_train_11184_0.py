a,b=map(int,input().split(" "))
lia,lib=[],[]
for i in range(1,a):
    for j in range(1,a):
        if i*i + j*j == a*a:
            lia.append([i,j])
fl=0
ans="NO"
for i in range(1,b):
    for j in range(1,b):
        if i*i + j*j == b*b:
            lib.append([i,j])
for [a,b] in lia:
    for [c,d] in lib:
        if a*c==b*d and b!=d:
            fl=1
            ans="YES"
            break
    if fl==1:
        break
print(ans)
if fl==1:
    print(0,0)
    print(-a,b)
    print(c,d)
