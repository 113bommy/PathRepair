s = str(input())
t = str(input())
s.split()
t.split()
count = 0
for i in range(len(t)):
    if t[i] not in s:
        count = 0
        break
    elif t[i] == s[count]:
        count += 1
    else:
        continue
print(count+1)
