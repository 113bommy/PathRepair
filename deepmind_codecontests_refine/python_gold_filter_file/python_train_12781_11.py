A, B, C = map(int, input().split())
K = int(input())

for i in range(K):
    if A >= B:
        B *= 2
    elif B >= C:
        C *= 2
print('Yes' if A<B<C else 'No')