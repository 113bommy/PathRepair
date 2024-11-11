
n = int(input())

s = bin(n)[2:]
s = '0' * (6-len(s)) + s

m = {0:4, 1:1, 2:3, 3:2, 4:0, 5:5}
res = 0
for i in range(5, -1, -1):
    if s[i] == '1':
        res += 2 ** (m[5-i])
print(res)
