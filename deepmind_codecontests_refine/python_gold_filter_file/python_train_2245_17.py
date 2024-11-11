n, k = input().split()
n, k = [int(n), int(k)]
s = str(input())
a = s.index('G')
b = s.index('T')
check = False
if a > b:
    s = s[::-1]
    a = s.index('G')
for i in range(a, n, k):
    if s[i] == '#':
        print("NO")
        check = True
        break
    elif s[i] == '.':
        pass
    elif s[i] == 'T':
        print("YES")
        check = True
        break
if check == False:
    print("NO")
    