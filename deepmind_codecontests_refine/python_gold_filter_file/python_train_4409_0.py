n,m=map(int,input().split())
co=[]
x,y=0,0
for i in range(n):
    c=input()
    for j in range(len(c)):
        if c[j]=='*':
            x^=j
            y^=i
print(y+1,x+1)