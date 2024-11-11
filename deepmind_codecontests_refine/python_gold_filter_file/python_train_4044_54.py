a=[2,1]
for i in range(90):
  a.append(a[-1]+a[-2])
print(a[int(input())])