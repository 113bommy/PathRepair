import sys

line = sys.stdin.readline().strip()

st = set()
po = -1
o = int()

#print(dir(st))

while line:
    c = line[0]
    line = line[1:]
    o = ord(c)-ord('a')
    if o<=po:
        continue
    elif o == po+1:
        po = o
    else:
        print("NO")
        exit(0)
        
print("YES")
