n = int(input())
a = input()
b = input()
count = 0
for i in range(n+1):
    if a[-i:] == b[:i]:
        count = i
print(2*n-count)