n=int(input())
x=1
for i in range(n):
    x=x*(i+1)%1000000007
print(x)
