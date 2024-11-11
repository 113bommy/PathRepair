n = int(input())
s = input()
b = 0
w = s.count(".")
l = [w]
for i in range(1, n + 1):
    if s[i - 1] == "#":
        b += 1
    if s[i - 1] == ".":
        w -= 1
    l.append(b + w)
print(min(l))