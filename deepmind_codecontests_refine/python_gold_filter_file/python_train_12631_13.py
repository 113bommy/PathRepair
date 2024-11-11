n,m = (int(i) for i in input().split())
b=list()
bl=True
for i in range(int(n)):
    b.append(input())
for i in b:
    for j in i:
        if i[0]!=j:
            bl=False
if bl:
    for i in range(n-1):
        if b[i]==b[i+1]:
            bl=False
    if bl:
        print("YES")
    else:
        print("NO")
else:
    print("NO")