n=int(input())
width,thickness=[],[]
one,two=[],[]
for _ in range(n):
    ti,wi=map(int,input().split())
    thickness.append(ti),width.append(wi)
    if ti==1:one.append(wi)
    if ti==2:two.append(wi)
one.sort(),two.sort()
one=[0]+one
two=[0]+two
for i in range(1,len(one)):
    one[i]=one[i-1]+one[i]
for i in range(1,len(two)):
    two[i]=two[i-1]+two[i]
ans=10e18
for i in range(len(one)):
    for ii in range(len(two)):
        thick=(i)+2*(ii)
        width=one[len(one)-i-1]
        width+=two[len(two)-ii-1]
        if width<=thick:ans=min(ans,thick)
print(ans)