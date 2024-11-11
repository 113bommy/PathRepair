[n, m] = [int(i) for i in input().split()]
s = [i for i in input()]
for i in range(m):
    [l, r, c1, c2] = [i for i in input().split()]
    for j in range(int(l) - 1, int(r)):
        if s[j] == c1:
            s[j] = c2;
print (''.join(s))