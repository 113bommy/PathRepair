def func():
    count100 = 0
    count200 = 0
    _ = input()
    arr = input().split()
    for item in arr:
        if item == "100":
            count100 += 1
        else:
            count200 += 1
    if count100 == 0 and count200 % 2 != 0:
        return False
    return not count100 % 2
    

print("YES" if func() else "NO")