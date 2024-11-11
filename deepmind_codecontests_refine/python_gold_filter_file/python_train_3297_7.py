import sys
input = sys.stdin.readline

n = int(input())

s = list(map(int, input().split()))
for i in range(n):
    q = s[i] % n
    if(q < i):
        s[i] += (i - q)
    elif(q > i):
        s[i] += n - (q - i)
ind = 0
for i in range(n):
    if(s[i] < s[ind]):
        ind = i
#print(*s)
print(ind + 1)