n=int(input())
p=[input().split() for _ in range(n)]
x=input()
ans=0
flag=False
for i in p:
    if i[0]==x:
        flag=True
        continue
    if flag:
        ans+=int(i[1])
print(ans)
