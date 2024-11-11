c=['o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n']
n,k=map(int, input().split())
u=c[:k]
p=" "
x=0
for ci in range(1,n+1):
    cc=u[x]
    if p[ci-1] == cc:
        cc=u[x]
    if x+1 == k: x=0
    else: x+=1
    p+=cc
print(p[1:])
