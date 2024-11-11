import string

n, k = map(int, input().split())
s = list(input())

for char in string.ascii_lowercase:
    for i in range(len(s)):
        if k == 0:
            break
        elif s[i] == char:
            s[i] = ''
            k -= 1

for char in s:
    print(char, end='')