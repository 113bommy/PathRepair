N = int(input())
print('Yes' if any(i * 4 + j * 7 == N for i in range(100) for j in range(100)) else 'No')
