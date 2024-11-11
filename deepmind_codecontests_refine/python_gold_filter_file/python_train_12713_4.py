from sys import stdin
fr,li = [int(x) for x in stdin.readline().split()]
red = (fr*2 + li - 1) // li
green = (fr*5 + li - 1) // li
blue = (fr*8  + li - 1) // li

print(red + green  + blue)
