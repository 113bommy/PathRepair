a = [int(i) for i in input().split()]
b = [int(i) for i in input().split()]
total = 0
for i in range(a[0]):
    if b[i]+a[1] <=5:
        total+=1
print(int(total/3))