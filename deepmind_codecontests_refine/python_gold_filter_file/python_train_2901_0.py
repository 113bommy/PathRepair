H,W = list(map(int,input().split()))

a = [input() for i in range(H)]

b = [[] for i in range(H)]
r = [[] for i in range(H)]
for i in range(H):
    for j in range(W):
        if i==0:
            b[i].append("#")
            r[i].append(".")
        elif i==H-1:
            b[i].append(".")
            r[i].append("#")
        elif a[i][j]=="#":
            b[i].append("#")
            r[i].append("#")
        elif j%2==0:
            b[i].append(".")
            r[i].append("#")
        elif j%2==1:
            b[i].append("#")
            r[i].append(".")

for i in range(H):
    ans = ""
    for j in range(W):
        ans = ans+b[i][j]

    print(ans)
print("")

for i in range(H):
    ans = ""
    for j in range(W):
        ans = ans+r[i][j]

    print(ans)
