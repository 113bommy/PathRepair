n, k =[int(x) for x in input().split()]
y = [int(x) for x in input().split()]
m = 0
for i in range(n):
    y[i] = 5-y[i]
y.sort()
if y[0]>=k:
    m = n
else:
    for i in range(1,n):
        if y[i-1]<k<=y[i]:
            m = n-i
            break
print(m//3)
