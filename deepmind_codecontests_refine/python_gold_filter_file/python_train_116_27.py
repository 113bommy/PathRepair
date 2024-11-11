n = int(input())
s = input()

first = [300000500] * 26
last = [-1] * 26

for i in range(n):
    val = ord(s[i]) - ord('a')
    first[val] = min(first[val], i)
    last[val] = max(last[val], i)

for i in range(25, -1, -1):
    for j in range(i - 1, -1, -1):
        if first[i] < last[j]:
            print("YES\n", first[i] + 1, last[j] + 1)
            exit(0)
print("NO")