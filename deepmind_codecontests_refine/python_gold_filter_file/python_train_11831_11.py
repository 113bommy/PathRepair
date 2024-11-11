a = ["a","e","i","o","u","1","3","5","7","9"]
b = list(input()); ans = 0
for i in range(len(b)):
    if b[i] in a: ans += 1
print(ans)