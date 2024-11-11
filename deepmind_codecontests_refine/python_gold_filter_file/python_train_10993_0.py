names=["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"]

n=int(input())

total=0
cur=1

while total+cur*5<n:
    total+=cur*5
    cur*=2

n-=total
print(names[(n-1)//cur])
