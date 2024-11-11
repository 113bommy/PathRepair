n = int(input())
s = input()

l = [-1 if s[i] == 0 else 1 for i in range(n)]

print(l.count(1) + l.count(-1) + 1)
