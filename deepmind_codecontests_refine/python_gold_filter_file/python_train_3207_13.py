s = input()
res = [0] * len(s)
cnt = 0
for i in range(len(s)):
    if s[i] == "R":
        cnt += 1
    else:
        res[i-1] += (cnt+1)//2
        res[i] += cnt//2
        cnt = 0
cnt = 0
for i in range(1, len(s)+1):
    if s[-i] == "L":
        cnt += 1
    else:
        res[-i] += cnt//2
        res[-i+1] += (cnt+1)//2
        cnt = 0
print(*res)