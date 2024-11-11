b = int(input())
g = int(input())
n = int(input())


count = 0

for i in range(n + 1):
    gt = n - i
    if (gt > g or i > b):
        continue
    count+=1;

print(count)