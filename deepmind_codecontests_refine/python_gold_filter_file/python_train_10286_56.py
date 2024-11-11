N = int(input())
p = [int(s) for s in input().split()]

print('YES' if sum(map(lambda x: x[0] == x[1], zip(p, sorted(p)))) >= N - 2 else 'NO')