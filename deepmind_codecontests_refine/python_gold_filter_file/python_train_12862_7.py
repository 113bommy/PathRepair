n=int(input())
f=0
ans=[]
for _ in range(n):
    a=input()
    if a.find("OO")!=-1 and not(f):
        a=a.replace("OO","++",1)
        f=1
    ans.append(a)
if f:
    print("YES")
    for i in range(n):
        print(ans[i])
else:
    print("NO")