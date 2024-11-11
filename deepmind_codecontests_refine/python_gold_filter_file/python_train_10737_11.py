input()
x=list(map(int, input().split()))+[0]
tmp=1
sushi=[]
listans=[]

for i in range(len(x)-1):
    if x[i+1]==x[i]:
        tmp+=1
    else:
        sushi.append((x[i],tmp))
        tmp=1

sushi.append((0,0))

for i in range(len(sushi)-1):
    listans.append(min(sushi[i][1],sushi[i+1][1]))

print(2*max(listans))