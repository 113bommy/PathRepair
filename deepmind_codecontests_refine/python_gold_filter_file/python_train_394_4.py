n, x = map(int, input().split(" "))
a = list(map(int, input().split(" ")))

a.sort()

count = 0
for a_i in a:
    x -= a_i
    if x < 0:
        break
    count += 1
print(count-(x>0))