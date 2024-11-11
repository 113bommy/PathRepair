def solve(a, b):
    i=0
    for j in range(len(b)):
        if j and i < len(a) - 1 and a[i+1] == b[j]:
            i += 1
        elif b[j] != a[i]:
            return False
    return i == len(a) - 1



t=int(input())
for _ in range(t):
    a=input()
    b=input()
    print('YES' if solve(a, b) else 'NO')
