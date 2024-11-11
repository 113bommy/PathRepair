a, b = map(int, input().split())
p = 1

for i in range(a, b):
    s = str(i + 1)
    p = p * int(s[len(s) - 1])

    if i - a == 100:
        break
    
print(p % 10)
