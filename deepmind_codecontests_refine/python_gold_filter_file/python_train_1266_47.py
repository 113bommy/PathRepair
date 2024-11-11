n=int(input())
a=[0,1,5]
for i in range(3,101):
    a.append(a[-1] + 4*(i-1))
print(a[n])
