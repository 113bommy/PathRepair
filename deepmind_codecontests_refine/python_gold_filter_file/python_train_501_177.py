N = int(input())
a = set(map(int, input().split()))
print(max(a) - min(a))