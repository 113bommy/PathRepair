def cross(c1, c2):
    return c1.real * c2.imag - c1.imag * c2.real

def print_cross_point(p1, p2, p3, p4):
    # p1 and p2 are end points of a segment.
    # p3 and p4 are end points of the other segment.
    base = p4 - p3
    hypo1 = p1 - p3
    hypo2 = p2 - p3
    d1 = abs(cross(base, hypo1)) / abs(base)
    d2 = abs(cross(base, hypo2)) / abs(base)
    cp = p1 + d1 / (d1 + d2) * (p2 - p1)
    print("{0:.10f} {1:.10f}".format(cp.real, cp.imag))

import sys

file_input = sys.stdin

sq = file_input.readline()

for line in file_input:
    x_p0, y_p0, x_p1, y_p1, x_p2, y_p2, x_p3, y_p3 = map(int, line.split())
    p0 = x_p0 + y_p0 * 1j
    p1 = x_p1 + y_p1 * 1j
    p2 = x_p2 + y_p2 * 1j
    p3 = x_p3 + y_p3 * 1j
    print_cross_point(p0, p1, p2, p3)