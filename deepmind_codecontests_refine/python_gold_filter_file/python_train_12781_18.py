R, G, B = map(int, input().split())
K = int(input())
for _ in range(K):
    if G <= R:
        G *= 2
    elif B <= G:
        B *= 2
print('Yes' if R < G < B else 'No')
