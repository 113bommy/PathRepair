a = int(input())
count = 0
mod = 0
for i in range(a):
    b = int(input())
    if b == 0:
        mod = 0
    c = b + mod
    if not c==0:
        count += c//2
        mod = c%2
print(count)