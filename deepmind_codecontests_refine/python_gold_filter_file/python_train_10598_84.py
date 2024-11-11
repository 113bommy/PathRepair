r,D,x = map(int,input().split())

for i in range(1,11):
    x = x * r - D
    print(x)