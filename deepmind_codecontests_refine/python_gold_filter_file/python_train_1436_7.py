n=int(input())
l=[]
for i in range(n):
    l.append(list(map(str,input().split())))
x=input()
ans=0
f=0
for i in l:
    if f==1:
        ans+=int(i[1])
    if i[0]==x:
        f=1
print(ans)
