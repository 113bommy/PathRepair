import math as mt
import itertools as it
import functools as ft

stdin = lambda type_ = "int", sep = " ": list(map(eval(type_), input().split(sep)))
joint = lambda sep = " ", *args: sep.join(str(i) if type(i) != list else sep.join(map(str, i)) for i in args)

n = int(input())
s = input()

i = 0
while i < len(s) - 1:
    if s[i] in "aeoiuy" and s[i + 1] in "aeiouy":
        s = s[:i + 1] + s[i + 2:]
        i -= 1
    i += 1

print(s)