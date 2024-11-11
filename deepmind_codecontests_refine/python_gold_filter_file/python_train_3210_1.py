a, b, k = [int(m) for m in input().split(" ")]

for i in range(a, min(a+k, b+1)):
    print(i)
for i in range(max(b+1-k, a+k), b+1):
    print(i)