def main():
    import sys
    input = sys.stdin.readline
    
    n = int(input())
    ans = []
    arr = list(map(int, input().split()))
    amt = [2 if x else 0 for x in arr]
    
    bottoms = []
    bottoms1 = []
    others = []
    idx = 0
    idx1 = 0
    
    for i in range(n-1, -1, -1):
        if arr[i] == 0:
            continue
        if arr[i] == 1:
            bottoms.append((i + 1, i + 1))
        if arr[i] == 2:
            if idx == len(bottoms):
                print(-1)
                return
            
            r, c = bottoms[idx]
            bottoms1.append((r, i + 1))
            idx += 1
        if arr[i] == 3:
            if idx == len(bottoms) and idx1 == len(bottoms1):
                print(-1)
                return
            elif idx1 == len(bottoms1):
                r, c = bottoms[idx]
                bottoms1.append((i + 1, i + 1))
                others.append((i + 1, c))
                idx += 1
            else:
                r, c = bottoms1[idx1]
                bottoms1.append((i + 1, i + 1))
                others.append((i + 1, c))
                idx1 += 1
    
    # if arr[-1] > 1:
    #     print(-1)
    #     return
    # elif arr[-1] == 1:
    #     amt[-1] -= 1
    #     ans.append((n, n))
    # x = -1
    # y = -1
    # rindex = n - 1
    # for i in range(n - 1, -1, -1):
    #     if arr[i] == 0:
    #         continue
    #     elif arr[i] == 1:
    #         amt[i] -= 1
    #         ans.append((i + 1, i + 1))
            
    #         if y == -1:
    #             x = i
    #             y = i + 1
    #     elif arr[i] == 2:
    #         if y == -1:
    #             print(-1)
    #             return
            
    #         amt[i] -= 1
    #         ans.append((y, i + 1))
    #     elif arr[i] == 3:
    #         if x == -1:
    #             print(-1)
    #             return
    #         while rindex > i and (rindex == x or not arr[rindex]):
    #             rindex -= 1
    #         if rindex == i:
    #             print(-1)
    #             return
    #         amt[i] -= 1
    #         amt[rindex] -= 1
    #         ans.append((i + 1, i + 1))
    #         ans.append((i + 1, rindex + 1))
    
    ans = others + bottoms + bottoms1
    print(len(ans))
    for (x, y) in ans:
        print(x, y)
    return 0

main()
