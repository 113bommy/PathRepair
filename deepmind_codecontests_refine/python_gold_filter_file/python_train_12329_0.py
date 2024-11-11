n = int(input())
s = input()
count = 0

for i in range(n):
    if s[i] == 'B':
        count += 2 ** i
print(count)