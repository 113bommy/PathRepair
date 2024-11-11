a,b=map(int,input().split())
k=[]
h=["W","G","B"]
l=0
for i in range(a):
        k.append(input().split())
for i in range(a):
    for j in range(b):
        if k[i][j] in h:
            l+=1
if l==a*b:
    print("#Black&White")
elif l!=a*b:
    print("#Color")


