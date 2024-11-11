for _ in range(int(input())):
    x = int(input())
    val = 0
    cnt = 0
    ptr = 1
    while x >= 0:
        val = (ptr * (ptr + 1)) // 2
        x -= val
        ptr = ptr * 2 + 1
        cnt += 1
    print(cnt - 1)
