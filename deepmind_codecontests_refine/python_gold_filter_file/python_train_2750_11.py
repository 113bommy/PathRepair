def bashnya(lst):
    a, count, max_height = sorted(lst), 0, 0
    last, current = -1, 0
    for elem in a:
        if elem == last:
            current += 1
        else:
            max_height = max(max_height, current)
            count += 1
            last, current = elem, 1
    max_height = max(max_height, current)
    return max_height, count


n = int(input())
b = [int(i) for i in input().split()]
print(*bashnya(b))
