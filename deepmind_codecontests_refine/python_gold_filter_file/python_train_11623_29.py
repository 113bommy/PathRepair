import sys

data = input().split(" ")
v1 = int(data[0])
v2 = int(data[1])
v3 = int(data[2])
vm = int(data[3])

a3min = max(v3, vm)
a3max = min(vm * 2, v3 * 2)
if a3max < a3min:
    print("-1")
    exit()

a2min = max(v2, vm * 2 + 1)
if a2min <= a3min:
    a2min = a3min + 1
a2max = v2 * 2
if a2max < a2min:
    print("-1")
    exit()

a1min = max(v1, vm * 2 + 1)
if a1min <= a2min:
    a1min = a2min + 1
a1max = v1 * 2
if a1max < a1min:
    print("-1")
    exit()

print("{}\n{}\n{}".format(a1min, a2min, a3min))
