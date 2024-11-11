#!/usr/bin/env/ python

buttons = int(input())
fastens = list(map(int, input().split()))
count = 0

if buttons == 1:
    if fastens[0] == 0:
        print ("NO")
        exit()
    else:
        print("YES")
        exit()
else:
    for fasten in fastens:
        if fasten == 0:
            count += 1
    if count == 1:
        print ("YES")
    else:
        print ("NO")
