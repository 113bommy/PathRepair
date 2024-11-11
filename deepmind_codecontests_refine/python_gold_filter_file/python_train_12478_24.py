N = int(input())
s = input()
t = input()
u = 0
for i in range(N):
    if s[-i - 1:] == t[:i + 1]:
        u = i + 1
print (N * 2 - u)