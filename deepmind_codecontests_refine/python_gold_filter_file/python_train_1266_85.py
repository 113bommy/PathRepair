a=[1]
for i in range(1,100):
    a.append(a[-1]+4*i)
x=int(input())
print(a[x-1])
