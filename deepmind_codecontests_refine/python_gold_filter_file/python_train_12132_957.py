a = str(bin(int(input())))[2:]
a = '0'*(6 - len(a)) + a
v1 = [0, 5, 3, 2, 4, 1]
v2 = [4, 3, 5, 2, 0, 1]
v3 = [5, 2, 0, 3, 1, 4]
v4 = [1, 2, 0, 3, 5, 4]

ans = ""
for i in v1:
    ans += a[i]
print(int(ans, 2))