if __name__ == '__main__':
    num_elements = int(input())
    arrs = list(map(int, input().split()))
    sorted_arrs = sorted(arrs)
    left = 0
    right = 0
    for index in range(num_elements):
        if arrs[index] != sorted_arrs[index]:
            left = index
            break

    for index in range(num_elements - 1, -1 , -1):
        if arrs[index] != sorted_arrs[index]:
            right = index
            break
    start, end = left, right
    while start < end:
        arrs[end], arrs[start] = arrs[start], arrs[end]
        start += 1
        end -= 1
    if arrs != sorted_arrs:
        print("no")
    else:
        print('yes')
        print(left + 1, right + 1)