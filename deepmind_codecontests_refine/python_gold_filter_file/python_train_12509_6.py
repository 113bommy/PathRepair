n=int(input())
a=list(map(int,input().split()))
b=[4,8,15,16,23,42]
c=[0]*6
i=0
x=0
while len(a)>x:
    if a[x]==b[i]:
        c[b.index(a[x])]+=1
        i=(i+1)%6
    elif a[x]<b[i]and (a[x]==b[0] or c[b.index(a[x])]<min(c[:b.index(a[x])])):
        c[b.index(a[x])]+= 1
    elif a[x]>b[i] and c[b.index(a[x])]<min(c[:b.index(a[x])]):
        c[b.index(a[x])]+=1
    x+=1

print(len(a)-min(c)*6)