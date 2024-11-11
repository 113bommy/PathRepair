n,m=map(int,input().split())
x=[int(i) for i in input().split()]
y=[int(i) for i in input().split()]
b=x[0]
x=x[1:]
g=y[0]
y=y[1:]
happyb=[0]*n 
happyg=[0]*m 
for i in x:
    happyb[i]=1 
for i in y:
    happyg[i]=1 
for i in range(100000):
    if happyb[i%n] or happyg[i%m]:
        happyb[i%n]=1 
        happyg[i%m]=1 
print('Yes' if sum(happyg)==m and sum(happyb)==n else 'No')