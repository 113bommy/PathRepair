def solve(arr, p):
    cur = "A" * 51
    for rank in p:
        if min(arr[rank - 1]) > cur:
            cur = min(arr[rank - 1])
        elif max(arr[rank - 1]) > cur:
            cur = max(arr[rank - 1])
        else:
            return False
    return True

n = int(input())
arr = list()

for i in range(n):
    arr.append(input().split())

p = list(map(int, input().split()))

print("YES") if solve(arr, p) else print("NO")
