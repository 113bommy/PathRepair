a = input()
ans = 0
b = ["a", "e", "i", "o", "u"]
for i in a:
    if ord(i) >= ord("0") and ord(i) <= ord("9"):
        ans += int(i) % 2
    else:
        ans += b.count(i)
print(ans)
