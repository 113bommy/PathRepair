N, A, B = map(int, input().split())
print(max(0, B*(N-2) - A*(N-2)  +1))
