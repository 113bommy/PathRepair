N = int(input())
S = input()

x = 0
for i in range(1, N+1):
    x = max(x, S[:i].count('I') - S[:i].count('D'))
print(x)
