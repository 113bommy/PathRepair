def go():
    keep = {}
    n, l = (int(i) for i in input().split(' '))
    matrix = [None] * n
    for i in range(n):
        matrix[i] = [i for i in input()]

    for i in range(n):
        for j in range(n):
            if matrix[i][j] == '.':
                h = 0
                v = 0
                for k in range(l):
                    if j + k < n and matrix[i][j + k] == '.':
                        h += 1
                    if i + k < n and matrix[i + k][j] == '.':
                        v += 1
                if h == l:
                    for k in range(l):
                        keep.setdefault((i, j + k), 0)
                        keep[(i, j + k)] += 1
                if v == l:
                    for k in range(l):
                        keep.setdefault((i + k, j), 0)
                        keep[(i + k, j)] += 1
    if len(keep) != 0:
        import operator
        result = max(keep.items(), key=operator.itemgetter(1))[0]
        return '{} {}'.format(result[0] + 1, result[1] + 1)
    return '1 1'

print(go())