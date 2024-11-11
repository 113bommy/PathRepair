import sys
s = input()
if len(s) <= 1:
    print(-1, -1)
else:
    for i in range(len(s) - 1):
        if s[i] == s[i + 1]:
            print(i + 1, i + 2)
            exit(0)
    for i in range(len(s) - 2):
        if s[i] == s[i + 2]:
            print(i + 1, i + 3)
            exit(0)
    print(-1, -1)
