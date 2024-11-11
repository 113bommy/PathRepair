n,m=map(int,input().split())
l=[]
c=0
x_xor,y_xor=0,0
for i in range(n):
    l.append(list(input()))
for i in range(n):
    for j in range(m):
        if l[i][j]=="*" :
            x_xor=x_xor^i
            y_xor=y_xor^j
            c+=1
        if c==3:
            break
print(x_xor+1,y_xor+1)