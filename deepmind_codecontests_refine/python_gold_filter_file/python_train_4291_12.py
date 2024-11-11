import sys
#input = sys.stdin.buffer.readline

n = int(input())
s = list(map(lambda x: 0 if x == 'B' else 1,list(input().strip())))
def flip(index):
    if s[index] == 0:s[index] = 1
    else:s[index] = 0
out = []
for i in range(1,len(s)-1):
    if s[i] == s[0]:continue
    flip(i); flip(i+1)
    out.append(i + 1)

if s[-1] == s[0]:
    print(len(out))
    print(*out)
elif (n-1)%2 != 0:
    print(-1)
else:
    for i in range(n-3,-1,-2):out.append(i+1)
    print(len(out))
    print(*out)
