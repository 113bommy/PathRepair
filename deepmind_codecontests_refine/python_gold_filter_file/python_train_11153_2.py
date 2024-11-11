n=int(input())
s=input()
good=["RGB", "RBG", "BRG", "BGR", "GBR", "GRB"]
v=0
minx=1000000
for i in range(6):
    w=0
    for j in range(n):
        if(s[j]!=good[i][j%3]):
            w+=1
    if(minx>w):
        minx=w
        v=i
print(minx)
for k in range(0,int(n/3)):
    print(good[v],end="")
for x in range(0,n%3):
    print(good[v][x],end="")