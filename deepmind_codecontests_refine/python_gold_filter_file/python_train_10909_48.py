n = int(input())
s = input()
result = 0
for i in range(1000):
    x = format(i, "03")
    p = 0
    for j in range(n):
        if s[j]==x[p]:
            p += 1
            if p==3:
                result += 1
                break
print(result)