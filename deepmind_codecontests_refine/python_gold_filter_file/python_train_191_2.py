def zan(total, flag):
    rest = 7200 - total if flag else (7200 - total) * 3
    t, rest = divmod(rest, 3600)
    h, s = divmod(rest, 60)
    print("{0:02d}:{1:02d}:{2:02d}".format(t, h, s))

while True:
    T, H, S = map(int, input().split())
    if T == -1:
        break
    total = T * 3600 + H * 60 + S
    for i in [1, 0]:
        zan(total, i)