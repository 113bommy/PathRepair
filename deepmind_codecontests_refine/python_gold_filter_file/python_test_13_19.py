n = int(input())

for i in range(n):
    s = input()
    w = (s.count('A') + s.count('C'))
    if w == (s.count('B')):
        print("YES")
    else: print("NO")