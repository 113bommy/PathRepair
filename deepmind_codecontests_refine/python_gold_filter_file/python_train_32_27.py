n = input().split()
x = int(n[1])
y = int(n[2])
n = int(n[0])
t = n -y
res = n * y / 100
if not res == round(res):
    res = int(res)+1

res = int(-x +res)
res = max(res,0)
print(res)