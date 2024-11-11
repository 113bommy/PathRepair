# import os

n = int(input())

m = int(input())

usb = []
for _ in range(n):
    usb.append(int(input()))
usb.sort(reverse=True)

c = 0
for i,item in enumerate(usb):
    c += item
    if c >=m:
        print(i+1)
        break
