a=int(input())
x=1
for i in range(1,a+1):
    x = x* i % (10**9+7)
print(x)
