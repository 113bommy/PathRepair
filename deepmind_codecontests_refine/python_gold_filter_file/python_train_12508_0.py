#main logic
def turn(maxgen, V, A, k, val):
    max_node = next(maxgen)
    left_node = get_prev(max_node)
    right_node = get_next(max_node)
    V[remove(max_node, A)] = val
    #right walk
    rcnt = 0
    while rcnt < k and right_node is not None:
        V[remove(right_node, A)] = val
        right_node = get_next(right_node)
        rcnt += 1
    #left walk
    lcnt = 0
    while lcnt<k and left_node is not None:
        V[remove(left_node, A)] = val
        left_node = get_prev(left_node)
        lcnt+=1

    return lcnt + rcnt + 1

#methods for linked list
def get_next(node):
    return node[1][1]

def get_prev(node):
    return node[1][0]

def pushback(value, prev_node):
    next_node = None
    new_node = [value, [prev_node, next_node]]
    if prev_node[1][1] is None:
        prev_node[1][1] = new_node
    else:
        raise Exception
    return new_node

def remove(node, A):
    (node_value, node_index), (node_prev, node_next) = node
    if node_prev is not None:
        node_prev[1][1] = node_next
    if node_next is not None:
        node_next[1][0] = node_prev
    A[node_value - 1] = None
    return node_index

#linked list constructor
def parseraw(raw, A):
    head = [None, [None, None]]
    temp = ''
    sep = ' '
    ind = 0
    lasti = len(raw) - 1
    for i, v in enumerate(raw):
        if v == sep or i == lasti:
            if i == lasti:
                temp+=v
            j = int(temp)
            if head[0] is None:
                head[0] = j, ind
                last_node = head
            else:
                last_node = pushback((j,ind), last_node)
            A[j-1] = last_node
            ind+=1
            temp = ''
        else:
            temp += v

def max_gen(A):
    for i in reversed(A):
        if i is not None:
            yield i

    




if __name__ == '__main__':
    #read data
    n, k = map(int, input().split())
    raw = input()
    #main part
    A = [None]*n
    V = [None]*n
    
    parseraw(raw, A)
    maxgen = max_gen(A)

    first = -1

    while n:
        val = 1 if first else 2
        n -= turn(maxgen, V, A, k, val)
        first = ~first
    print(*V, sep = '')
