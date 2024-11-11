k=int(input())
l=int(input())
m=int(input())
n=int(input())
d=int(input())
i=1
count=0
for i in range(d+1):
    if(i%k!=0 and i%l!=0 and i%m!=0 and i%n!=0): count+=1 
print(d-count)