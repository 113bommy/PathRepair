n, a, b = int(input()), list(input()), list(input())   
ans = []
count = 0
for i in range(n):
    if a[i] != b[i]:
        ans.append((a[i], b[i]))
        count += 1
        for j in range(i+1, n):
            if a[j] == a[i]:
                a[j] = b[i]
            if b[j] == a[i]:
                b[j] = b[i]
print(count)
for each in ans:
    print(*each)
        