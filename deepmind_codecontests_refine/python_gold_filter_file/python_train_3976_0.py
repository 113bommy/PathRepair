q = int(input())
while q:
    Str, Int, Exp = map(int, input().split())
    Answer = 0
    if Str + Exp <= Int:
        print(0)
    else:
        left = 0
        right = Exp + 1
        while right - left > 1:
            mid = (right + left) // 2
            if Str + Exp - mid > Int + mid:
                left = mid
            else:
                right = mid
        print(left + 1)
    q -= 1


