ans = []
for i in range(int(input())):
    n = int(input())
    s = list(input())
    if '>' in s and '<' in s:
        a = 0
        for i in range(n):
            if s[i] == '-' or s[i - 1] == '-':
                a += 1
        ans.append(a)
    else:
        ans.append(n)
print('\n'.join(map(str, ans)))
