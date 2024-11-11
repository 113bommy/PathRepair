for _ in range(int(input())):
    n = int(input())
    l = list(map(int, input().split()))
    min_sum = l[0] + l[1]
    third_index = 0
    for i in range(n):
        if l [i] >= min_sum:
            third_index = i + 1
            break
    
    if third_index:
        print(1, 2, third_index)
    else:
        print(-1)