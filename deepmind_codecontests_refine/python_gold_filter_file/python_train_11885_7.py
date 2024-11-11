n, m=map(int, input().split())
a=[]
b=[]
x=0
y=0
for i in range(m):
    x, y= map(int, input().split())
    a.append(x)
    b.append(y)
x=a[0]
y=0
ans=1
fa=1
fb=1
fc=1
fd=1
if m==1:
    print("YES")
    quit()
for i in range (1, m):
    if a[i]!=x and a[i]!=y and b[i]!=x and b[i]!=y:
        y=a[i]
        for j in range(i+1, m):
            if a[j] != x and a[j] != y and b[j] != x and b[j] != y:
                fa = 0
        if fa == 1:
            print("YES")
            quit()
        y = b[i]
        for j in range(0, m):
            if a[j] != x and a[j] != y and b[j] != x and b[j] != y:
                fb = 0
        if fb == 1:
            print("YES")
            quit()
        break
    if i+1==m:
        print("YES")
        quit()
x=b[0]
for i in range(1, m):
    if a[i]!=x and a[i]!=y and b[i]!=x and b[i]!=y:
        y=a[i]
        for j in range(0, m):
            if a[j] != x and a[j] != y and b[j] != x and b[j] != y:
                fc = 0
        if fc == 1:
            print("YES")
            quit()
        y = b[i]
        for j in range(0, m):
            if a[j] != x and a[j] != y and b[j] != x and b[j] != y:
                fd = 0
        if fd == 1:
            print("YES")
            quit()
        break
    if i+1==m:
        print("YES")
        quit()
print("NO")