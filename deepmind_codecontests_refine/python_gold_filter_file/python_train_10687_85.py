x = (input()).split()
s = int(x[0])
n = int(x[1])
for i in range(n):
    if s % 10 != 0:
        s = s - 1
    else:
        s = s // 10
print(s)
