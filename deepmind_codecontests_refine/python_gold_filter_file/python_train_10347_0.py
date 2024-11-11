#!/usr/bin/python3

n = int(input())
s = list(input())
l = list(input())
a = len([_ for _ in zip(s, l) if _ == ('1', '1')])
b = len([_ for _ in zip(s, l) if _ == ('1', '0')])
c = len([_ for _ in zip(s, l) if _ == ('0', '1')])
f = b + (a + 1) // 2
s = c + a // 2
if f > s:
    print('First')
elif f + 1 < s:
    print('Second')
else:
    print('Draw')

