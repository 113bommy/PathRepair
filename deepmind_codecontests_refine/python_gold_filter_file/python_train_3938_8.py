s = list(input())
n = len(s)

if s[0] == '0' or s[n-1] == '1':
    print(-1)
    exit()

for i in range(n-1):
    if s[i] != s[n-2-i]:
        print(-1)
        exit()

p = n
for i in range(n-2,-1,-1):
    print(p,i+1)
    if s[i] == '1':
        p = i+1