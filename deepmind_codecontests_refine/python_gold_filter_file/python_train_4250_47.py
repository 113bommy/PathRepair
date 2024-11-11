A,B,K=map(int,input().split())
g=[]
for i in range(1,101):
    if A%i==0 and B%i==0:
        g.append(i)
print(g[-K])
