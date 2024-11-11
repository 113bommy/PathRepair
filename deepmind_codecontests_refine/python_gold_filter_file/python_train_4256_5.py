N = int(input())
L = list(map(int, input().split()))

L.sort(reverse=True)

print(sum(L[1::2]))