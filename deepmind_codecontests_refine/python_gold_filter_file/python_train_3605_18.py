import sys

line = sys.stdin.readlines()

cans = int(line[0].strip())

volumes = [int(x) for x in line[1].strip().split()]
caps =  [int(x) for x in line[2].strip().split()]

caps = sorted(caps)
if(caps[-1] + caps[len(caps) - 2] >= sum(volumes)):
    print("YES")
else:
    print("NO")

