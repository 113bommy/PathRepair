k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
t=0
for i in range(1,d+1):
    if i%k!=0 and i%l!=0 and i%m!=0 and i%n!=0:
        t+=1
print(d-t)