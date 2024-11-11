# http://tutuz.hateblo.jp/entry/2018/12/09/220715

inf = float('inf')

n = int(input())
coordinates = [tuple(map(int, input().split())) for _ in range(n)]

parity = None
can_make = True
for coordinate in coordinates:
    if parity is None:
        parity = sum(coordinate) % 2
    else:
        if parity != sum(coordinate) % 2:
            can_make = False
            break

if not can_make:
    print(-1)
    exit()
    # 到達可能な頂点はxy座標の和のパリティが一致している必要がある

if parity == 0:
    d = [pow(2, i) for i in range(31 + 1)] + [1]
    # 奇数は1だけなので、1を追加して、全ての腕の合計が偶数になるようにする
else:
    d = [pow(2, i) for i in range(31 + 1)]
    # 奇数は1だけなので、全ての腕の合計は奇数になる
d.sort(reverse=True)

ans = []
for x, y in coordinates:
    u = x + y
    v = x - y
    # 45度回転する
    # u,vの最大値はx,yの2倍=2*10**9
    # 2 ** 31 > 2 * (10 ** 9) なので、2**31までの二冪で大丈夫そう
    # [1, 2, ..., 2 ** 31]
    # L(-d,-d)R(+d,+d)U(+d,-d)D(-d,+d)
    # なので、一つのdで、uでは加算、vでは減算などでき、二冪一セットで足りる
    curu, curv = 0, 0
    ops = ''
    for dd in d:
        dist = inf
        op = ''
        det_du, det_dv = 0, 0
        for c, (du, dv) in zip('LRDU', [(-1, -1), (1, 1), (-1, 1), (1, -1)]):
            t = abs(curu + du * dd - u) + abs(curv + dv * dd - v)
            if dist > t:
                op = c
                dist = t
                det_du = du
                det_dv = dv
        ops += op
        curu += det_du * dd
        curv += det_dv * dd
    if (curu, curv) == (u, v):
        ans.append(ops)
    else:
        print(-1)
        # print('不一致', curx, cury, x, y)

print(len(d))
print(*d)
print(*ans, sep='\n')
