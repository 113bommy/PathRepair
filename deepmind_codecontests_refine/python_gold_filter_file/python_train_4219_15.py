import math
from sys import stdin
input = stdin.readline
lines = int(input())
size = int(input())
usb = []
for i in range(lines):
    usb.append(int(input()))
usb.sort(reverse=True)
num = 0
total = 0
for i in range(lines):
    if(total < size):
        total += usb[i]
        num += 1
    # print("a", total)
print(num)
