def solve(A,B,C,D, level):
    E = 3**level
    if level == -1:
        return int(abs(A-C) + abs(B-D))
    a,b,c,d = A//E, B//E, C//E, D//E
    if a != c and b != d:
        return int(abs(A-C) + abs(B-D))

    if a == c and b==d:
        return solve(A,B,C,D,level-1)

    if a != c and b==d:
        A,B,C,D = B,A,D,C
        a,b,c,d = b,a,d,c

    if b != d and a == c:
        if a%3 != 1:
            return solve(A,B,C,D,level-1)
        if abs(b-d) == 1:
            return solve(A,B,C,D,level-1)

        if B > D:
            A, B, C, D = C, D, A, B
            a, b, c, d = c, d, a, b

        x = E * a -1
        y1 = E * (b+1) -1
        y2 = E * d
        d = abs(x-A) + abs(y1-B) + abs(y1-y2) + abs(x-C) + abs(y2-D)
        x = E *(a+1)
        d2 = abs(x-A) + abs(y1-B) + abs(y1-y2) + abs(x-C) + abs(y2-D)
        return min(d,d2)

N = int(input())

for i in range(N):
    sg = [int(j.strip())  for j in input().split(' ')]
    s,g = [sg[0]-1,sg[1]-1],[sg[2]-1,sg[3]-1]
    A,B,C,D = s[0],s[1],g[0],g[1]
    print(solve(A,B,C,D,30))
