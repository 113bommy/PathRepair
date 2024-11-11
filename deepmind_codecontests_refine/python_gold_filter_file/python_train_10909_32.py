n = int(input())
s = input()
cnt = 0

for i in range(1000):
    c = [i // 100, (i // 10) % 10, i % 10]
    f = 0
    for j in range(n):
        if s[j] == str(c[f]): f+=1
        if f == 3: break
    if f == 3: cnt += 1
print(cnt)