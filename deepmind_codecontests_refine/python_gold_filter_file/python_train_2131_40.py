def contains_Eight(num):
    return True if '8' in str(num) else False


n = int(input())

for i in range(1, 17):
    n += 1

    if contains_Eight(n):
        print(i)
        break
