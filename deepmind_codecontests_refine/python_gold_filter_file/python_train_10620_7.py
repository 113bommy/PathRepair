import sys

class Node():
    def __init__(self,key):
        self.key = key
        self.left = None
        self.right = None

def insert(t, z):
    y = None
    x = t
    while x is not None:
        y = x
        if z.key < x.key:
            x = x.left
        else:
            x = x.right

    if y is None:
        return z
    else:
        if z.key < y.key:
            y.left = z
        else:
            y.right = z
        return t

def in_order(t):
    s = ""
    l = []
    curr = t
    while True:
        while curr is not None:
            l.append(curr)
            curr = curr.left
        if curr is None and len(l) == 0:
            break
        else:
            curr = l.pop()
            s += " " + str(curr.key)
            curr = curr.right
    return s

def pre_order(t):
    s = ""
    l = []
    curr = t
    while True:
        while curr is not None:
            s += " " + str(curr.key)
            l.append(curr)
            curr = curr.left
        if curr is None and len(l) == 0:
            break
        else:
            curr = l.pop()
            curr = curr.right
    return s

t = None
n = sys.stdin.readline()
lines = sys.stdin.readlines()
for line in lines:
    com = line.split()
    if line[0] == "i":
        t = insert(t, Node(int(com[1])))
    else:
        print(in_order(t))
        print(pre_order(t))