N = int(input())
S = input()
ans = 0
for i in range(1000):
    tmp = str(i).zfill(3)
    count = 0
    for k in S:
        if k == tmp[count]:
            count += 1
        if 3 == count:
            ans += 1
            break
print(ans)