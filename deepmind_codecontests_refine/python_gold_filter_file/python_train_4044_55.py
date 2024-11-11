n=int(input())
a=[2,1]
for i in range(n):
    a.append(a[-1]+a[-2])
print(a[n])