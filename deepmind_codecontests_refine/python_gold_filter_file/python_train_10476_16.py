s = list(input())
d = len(s)
count = 0

for i in range(d-2):
    for j in range(i+1, d-1):
        for k in range(j+1, d):
            if s[i] == "Q" and s[j] == "A" and s[k] == "Q":
                count += 1

print(count)
