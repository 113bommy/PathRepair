n=int(input())

a=[2,1]
for i in range(n):
    a.append(a[i+1]+a[i])

print(a[n])
