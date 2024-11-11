N, A, B = [int(i) for i in input().split()]

print(["Alice", "Borys"][(B - A) % 2])