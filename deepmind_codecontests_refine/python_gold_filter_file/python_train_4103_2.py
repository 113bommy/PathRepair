inp=input().split(" ")
n=int(inp[0])
m=inp[1]
k=int(inp[2])

blich={}
for i in range(n):
    ass = (input().split(" "))
    if ass[0] in blich and int(blich[ass[0]]) > int(ass[1] )or ass[0] not in blich:
        blich[ass[0]] = ass[1]

res=0
for x in blich.values():
    res+=int(x)
print(res) if res<=k else print(k)