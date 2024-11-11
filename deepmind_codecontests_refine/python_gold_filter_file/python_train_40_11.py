a,b = map(int,input().split())
sumh = a
while a>=1:
    sumh = sumh + (a / b)
    a = a / b
print(int(sumh))

