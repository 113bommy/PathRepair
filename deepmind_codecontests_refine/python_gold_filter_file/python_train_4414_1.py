__author__ = 'Eddie'
import sys


def get_filehandler(is_file):
    if is_file:
        return open(file="data")
    else:
        import sys

        return sys.stdin


# custom starts

def get_weighted_distance(vertices, pfree):
    return [((p[0] - pfree[0]) ** 2 + (p[1] - pfree[1]) ** 2) ** 0.5 / p[2] for p in vertices]



def get_error(distance):
    p1, p2, p3 = distance
    avg_p = (p1 + p2 + p3) / 3
    return (avg_p - p1) ** 2 + (avg_p - p2) ** 2 + (avg_p - p3) ** 2


if __name__ == '__main__':
    fh = get_filehandler(is_file=False)
    # fh = get_filehandler(is_file=True)
    vertices = [[float(x) for x in line] for line in map(str.split, fh.readlines())]
    pfree = [sum([v[0] for v in vertices]) / 3, sum(v[1] for v in vertices) / 3]
    error = get_error(get_weighted_distance(vertices, pfree))
    d = 2
    while True:
        error = get_error(get_weighted_distance(vertices, pfree))
        # print(error)
        if error < 1E-8:
            print("{:.5f} {:.5f}".format(pfree[0], pfree[1]))
            break
        if get_error(get_weighted_distance(vertices, (pfree[0] + d, pfree[1]))) < error:
            pfree[0] += d
            continue
        if get_error(get_weighted_distance(vertices, (pfree[0] - d, pfree[1]))) < error:
            pfree[0] -= d
            continue
        if get_error(get_weighted_distance(vertices, (pfree[0], pfree[1] + d))) < error:
            pfree[1] += d
            continue
        if get_error(get_weighted_distance(vertices, (pfree[0], pfree[1] - d))) < error:
            pfree[1] -= d
            continue
        d *= 0.5
        if d < 1E-5:
            break


