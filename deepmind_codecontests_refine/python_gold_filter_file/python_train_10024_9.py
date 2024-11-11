def max_min(_soldiers, _heights):
    _max = _min = _heights[0]
    _holder = ""
    count = 0
    for x in _heights:
        if int(x) > int(_max):
            _max = x
        if int(x) < int(_min):
            _min = x
    val = _heights.index(_max) + _heights[::-1].index(_min)
    if val >= int(_soldiers):
        val -= 1
    return val


if __name__ == "__main__":
    _soldiers = input()
    _heights = list(map(int, input().split()))
    print(max_min(_soldiers, _heights))
