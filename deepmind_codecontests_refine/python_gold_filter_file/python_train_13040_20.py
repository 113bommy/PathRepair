size = int(input())

for x in range(size):
    min_1 = 1000000000
    min_2 = 1000000000
    length = int(input())
    first = []
    second = []
    first_arr = input().split()
    second_arr = input().split()
    count = 0
    for j in range(length):
        a = int(first_arr[j])
        b = int(second_arr[j])
        first.append(a)
        second.append(b)
        if(a < min_1):
            min_1 = a
        if(b < min_2):
            min_2 = b
    for s in range(length):
        a_diff = abs(first[s] - min_1)
        b_diff = abs(second[s] - min_2)
        if(a_diff < b_diff):
            mm = a_diff
        else:
            mm = b_diff
        count += abs(a_diff-b_diff) +mm
    print(count)
