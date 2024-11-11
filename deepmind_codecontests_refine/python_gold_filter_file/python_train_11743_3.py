N = int(input())
for i in range(N-1):
    print(*[(i^j).bit_length() for j in range(i+1, N)])