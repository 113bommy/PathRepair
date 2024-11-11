s = input()
for i in range(8):
    if s[:i] + s[i - 7:] == "keyence":
        print("YES")
        exit()
print("NO")