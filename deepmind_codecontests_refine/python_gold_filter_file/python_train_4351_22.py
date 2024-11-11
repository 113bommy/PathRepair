a = list(map(int,input().split()))
b = list(map(int,input().split()))
c = list(map(int,input().split()))
d = [a[0],b[0],c[0]]
e = [a[1],b[1],c[1]]
f = [a[2],b[2],c[2]]
g = [a[0],b[1],c[2]]
h = [a[2],b[1],c[0]]

n = int(input())

bs = []
for _ in range(n):
    bs.append(int(input()))
       
for l in [a,b,c,d,e,f,g,h]:
    if (l[0] in bs) and (l[1] in bs) and (l[2] in bs):
        print("Yes")
        break
else:
    print("No")
