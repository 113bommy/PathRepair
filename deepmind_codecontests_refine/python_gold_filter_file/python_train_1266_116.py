

n = int(input())
a = []
a.append(1)
for i in range(1,101):
    a.append(a[i-1]+4*i)
print(a[n-1])