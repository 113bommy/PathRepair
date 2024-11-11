n = int(input())
a = input()
b = input()
res = 0
for i in range(n//2):
    x, y, z, w = a[i], b[i], a[n-i-1], b[n-i-1]
    if (x==y and z==w or x==z and y==w or x==w and y==z):
        continue
    elif (x==y or x==w or z==y or z==w or y==w):
        res+= 1
    else:
        res += 2
if (n%2 == 1):
    if (a[n//2] != b[n//2]):
        res += 1
print(res)
