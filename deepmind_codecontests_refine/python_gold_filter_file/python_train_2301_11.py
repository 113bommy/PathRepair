a = input().split()
n = int(a[0])
k = int(a[1])
b = input().split()
c = [0]*100
x = 0
max = 0
for i in range(n):
    c[int(b[i])-1] += 1
    if c[int(b[i])-1] > max:
        max = c[int(b[i])-1]

max = (max - 1)//k + 1
for i in range(100):
    if c[i] != 0:
        x += k*max - c[i]
print(x)
