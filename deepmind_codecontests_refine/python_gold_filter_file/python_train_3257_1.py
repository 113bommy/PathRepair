def solve():
    n, w = (int(x) for x in input().split())
    weights = [(int(x), i) for i, x in enumerate(input().split())]
    weights = [x for x in weights if x[0] <= w]

    for x, i in weights:
        if x >= (w + 1) // 2:
            print(1)
            print(i + 1)
            return
    
    # weights = [x for x in weights if x[0] < w // 2]
    
    curr_sum = 0
    curr_ans = []
    for x, i in weights:
        if curr_sum < (w + 1) // 2:
            curr_sum += x
            curr_ans.append(i + 1)
        else:
            break
    
    if curr_sum < (w + 1) // 2:
        print(-1)
        return
    
    print(len(curr_ans))
    print(*curr_ans)

if __name__ == "__main__":
    for _ in range(int(input())):
        solve()