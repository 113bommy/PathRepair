from collections import namedtuple
Node = namedtuple('Node', ['p', 'left', 'right'])

def insert(T, z):
    p = None
    x = T['root']
    while x != None:
        p = x
        if z < x: x = T[x].left
        else    : x = T[x].right

    T[z] = Node(p, None, None)

    if p == None:
        T['root'] = z
    elif z < p: T[p] = Node(T[p].p, z, T[p].right)
    else      : T[p] = Node(T[p].p, T[p].left, z)

 
def getInorderList(T, i):
    l = T[i].left
    r = T[i].right
    if l: yield from getInorderList(T, l)
    yield i
    if r: yield from getInorderList(T, r)


def getPreorderList(T, i):
    l = T[i].left
    r = T[i].right
    yield i
    if l: yield from getPreorderList(T, l)
    if r: yield from getPreorderList(T, r)


if __name__=='__main__':
    m = int(input())

    T = {}
    T['root'] = None
    for _ in range(m):        
        op = input().split()
        if op[0] == 'insert': insert(T, int(op[1]))
        else:
            print("",*getInorderList(T, T['root']))
            print("",*getPreorderList(T, T['root']))