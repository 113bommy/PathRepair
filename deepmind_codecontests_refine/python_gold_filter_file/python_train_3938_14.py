s = list(input())
n = len(s)
if s[-1] == "1":
    print(-1)
    exit()
if s[:-1] != s[:-1][::-1]:
    print(-1)
    exit()
if s[0] == "0":
    print(-1)
    exit()

before = -1
for i in range(n // 2):
    if s[i] == "1":
        num = i - before
        for j in range(num):
            print(before+2, i+2-j)
        before = i

for j in range(n-2-before):
    print(before+2, before+3+j)





