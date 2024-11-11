n = int(input())
s = input()
t = input()

p = 0
for i in range(1,n+1):
    if s[-i:] == t[:i]:
        p = i
print(len(s+t[p:]))