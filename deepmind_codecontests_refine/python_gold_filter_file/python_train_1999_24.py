class Node:
    def __init__(self, val):
        self.next = None
        self.id = val
        
def process(A, k):
    n = len(A)
    p1 = Node(A[0])
    p2 = None
    my_set = set([A[0]])
    curr = 1
    for i in range(1, n):
        if A[i] not in my_set:
            new_node = Node(A[i])
            my_set.add(A[i])
            if p2 is None:
                p2 = new_node
                p1.next = p2
            else:
                p2.next = new_node
                p2 = p2.next
            if curr < k:
                curr+=1
            else:
                v1 = p1.id
                my_set.remove(v1)
                p1 = p1.next 
      #  print(i, p1.id)
    answer = []
    while p1 != None:
        answer.append(p1.id)
        p1 = p1.next 
    return answer[::-1]

n, k = [int(x) for x in input().split()]
A = [int(x) for x in input().split()]
answer = process(A, k)
print(len(answer))
print(' '.join(map(str, answer)))
        
        
    