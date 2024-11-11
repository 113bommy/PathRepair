#!/usr/bin/env python3
import sys

v, h = list(map(lambda x: int(x), sys.stdin.readline().split(' ')))
vs = []
hs = []
for i in range(v):
	vs.append(int(sys.stdin.readline()))
vs.sort()
vs.append(10 ** 9)
for i in range(h):
	x1, x2, y = list(map(lambda x: int(x), sys.stdin.readline().split(' ')))
	if x1 == 1:
		hs.append([x1, x2, y])


def sort_x2(val):
	return val[1]


hs.sort(key=sort_x2)

hsl = len(hs)
vsl = len(vs)


res = v + h
hi = 0
for vi, v in enumerate(vs, start=0):
	while hi < hsl and hs[hi][1] < v:
		hi += 1
	res = min(res, vi + hsl - hi)


print(res)
