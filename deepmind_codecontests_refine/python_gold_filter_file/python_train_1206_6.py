s = input()
new = "heidi"
found = 0
for i in range (len(s)):
    if s[i] == new[found]:
        found += 1
        if found == len(new):
            print("YES")
            exit(0)
    else:
        continue
print("NO")