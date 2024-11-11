from sys import stdin

inp = stdin.readline
n = int(inp().strip())
s, t = inp().strip(), inp().strip()

abc = ['a','b','c']


for i in abc:
    for j in abc:
        if i != j:
            for k in abc:
                if i != j and j != k and i != k:
                    ans = ''.join([i, j, k])
                    ans = ans*n
                    if s not in ans and t not in ans:
                        print("YES")
                        print(ans)
                        exit()
                    ans2 = ''.join([i]*n + [j]*n + [k]*n)
                    if s not in ans2 and t not in ans2:
                        print("YES")
                        print(ans2)
                        exit()

print("NO")
exit()

