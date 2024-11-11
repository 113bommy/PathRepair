"""http://codeforces.com/problemset/problem/459/A"""

def solve(xa, ya, xb, yb):
    vertices = set([(xa, ya), (xb, yb)])
    dx = abs(xa - xb)
    dy = abs(ya - yb)
    if (xa != xb) and (ya != yb) and (dx != dy):
        return '-1'
    x = min(xa, xb)
    y = min(ya, yb)
    side = max(dx, dy)  # need this to avoid dx=0 or dy=0

    vertices.add((x, y))
    vertices.add((x + side, y))
    vertices.add((x, y + side))
    vertices.add((x + side, y + side))
    vertices.remove((xa, ya))
    vertices.remove((xb, yb))

    res = ' '.join('{} {}'.format(i[0], i[1]) for i in vertices)
    return res.strip()

def test():
    parse = lambda st: [int(x) for x in st.split()]
    assert solve(*parse('0 0 0 1')) == '1 0 1 1'

if __name__ == '__main__':
    # test()
    print(solve(*[int(x) for x in input().split()]))
