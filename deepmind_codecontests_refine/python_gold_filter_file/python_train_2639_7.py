# https://codeforces.com/problemset/problem/1/C

import itertools
import math

EPS = 1e-3

def get_vector(first, second):
    return tuple(y - x for x, y in zip(first, second))


def get_mid_perpendicular(first, second):
    vector = get_vector(first, second)
    mid = tuple((x + y) / 2 for x, y in zip(first, second))
    return (vector[0], vector[1], vector[0] * mid[0] + vector[1] * mid[1])


def find_intersection(first, second):
    det = first[0] * second[1] - first[1] * second[0]
    inv = ((second[1] / det, -first[1] / det), (-second[0] / det, first[0] / det))
    return (inv[0][0] * first[2] + inv[0][1] * second[2], inv[1][0] * first[2] + inv[1][1] * second[2])


def get_angle(first, second):
    return abs(math.atan2(first[1], first[0]) - math.atan2(second[1], second[0]))


def compute_min_area(points):
    mid_perpendicular1 = get_mid_perpendicular(points[0], points[1])
    mid_perpendicular2 = get_mid_perpendicular(points[1], points[2])
    intersection = find_intersection(mid_perpendicular1, mid_perpendicular2)
    vectors = [get_vector(intersection, p) for p in points]
    angles = [get_angle(vectors[i], vectors[j]) for i in range(3) for j in range(3) if i < j]
    for n in itertools.count(3):
        if all(abs(math.sin(a * n / 2)) < EPS for a in angles):
            v = vectors[0]
            return n * (v[0]**2 + v[1]**2) * math.sin(2 * math.pi / n) / 2


if __name__ == '__main__':
    points = []
    for _ in range(3):
        x, y = map(float, input().split())
        points.append((x, y))
    result = compute_min_area(points)
    print(f'{result:.8f}')