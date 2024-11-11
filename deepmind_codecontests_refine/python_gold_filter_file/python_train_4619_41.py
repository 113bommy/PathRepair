n = int(input())
count = 0
for i in range(n):
    x = input()
    if x.count('1') >= 2:
        count += 1
print(count)