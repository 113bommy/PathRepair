a = int(input())
b = list(map(int, input().split()))

print("EASY" if sum(b) == 0 else "HARD")