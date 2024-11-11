s = input()
n, m = list(map(int, s.split()))
s = input()
l = list(map(int, s.split()))
remain = n
model = 1
count = 0
for i in range(0, m):
    q = n%l[i]
    if q < remain:
        remain = q
        model = i+1
        count = n//l[i]
print(model, count)
        