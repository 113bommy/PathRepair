def check(a,b,c):
    if a+c>b:
        return True
    else:
        return False

n=int(input())
a=list(map(int,input().split()))
a.sort(reverse=True)
b=[]
for i in range(0,n,2):
    b.append(a[i])
c=[]
for i in range(1,n,2):
    c.append(a[i])
c.reverse()
for i in c:
    b.append(i)
fg=0
if check(b[0],b[-1],b[-2]) and check(b[1],b[0],b[-1]):
    for i in range(n-2):
        if not check(b[i],b[i+1],b[i+2]):
            fg=1
            break
else:
    fg=1
if fg==1:
    print("NO")
else:
    print("YES")
    for i in range(n):
        print(b[i],end=" ")