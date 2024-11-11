n = int(input())
m = int(input())
M = []
for i in range(0, n):
    M.append(int(input()))
M=sorted(M,reverse=True)
c = 0
while m > 0:
    m -= M[c]
    c += 1
print(c)
