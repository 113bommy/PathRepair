n=int(input())
while n>4:
    a=n-5
    if a%2==0:
        n=a//2
    else:
        n=(a+1)//2
print(["Sheldon", "Leonard", "Penny", "Rajesh", "Howard"][n-1])