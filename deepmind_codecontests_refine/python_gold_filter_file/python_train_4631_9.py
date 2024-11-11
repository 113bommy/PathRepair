n = str(input())
for i in range(10):
    if i > 9 - i:
        n = n.replace(str(i), str(9 - i))
if n[0] == "0":
    n = "9" + n[1:]
print(int(n))
