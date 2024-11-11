T = int(input())


# def find(arr):
#     if len(arr) == 1:
#         return True
#     ret = False
#     for i in range(len(arr)):
#         for j in range(i+1, len(arr)):
#             ai, aj = arr[i], arr[j]
#             if abs(ai - aj) <= 1:
#                 ret = ret or (find(arr[:i] + arr[i+1:])
#                               or find(arr[:j]+arr[j+1:]))
#     return ret


def find2(arr):
    arr = sorted(arr)
    for i in range(1, len(arr)):
        if abs(arr[i-1] - arr[i]) >= 2:
            return False
    return True


for _ in range(T):
    N = int(input())
    board = list(map(int, input().split()))
    if find2(board):
        print("YES")
    else:
        print("NO")
