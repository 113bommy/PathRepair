k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
x=0
for i in range(1,d+1):
    if i%k==0 or i%l==0 or i%m==0 or i%n==0:
        x=x+1
print(x)
