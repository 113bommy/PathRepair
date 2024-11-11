n, k = [int(i) for i in input().split()]
numbers = [int(i) for i in input().split()]
k -= 1

def right_isEquall():
    for i in range(k, n):
        if numbers[i] != numbers[k]:
            return False
    return True

def get_left():
    for i in range(k, -1, -1):
        if numbers[i] != numbers[k]:
            return i
    return -1

def main():
    if right_isEquall():
        print(get_left() + 1)
    else:
        print(-1)

main()