s = input()
t = input()

count = 0
for i in range(len(t)):
    if t[i] == s[count]:
        count += 1

print(count + 1)