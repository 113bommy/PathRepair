f = input().strip().split()
q = []
for e in f:
    if e == '+':
        q.append(q.pop() + q.pop())
    elif e == '-':
        q.append(-q.pop() + q.pop())
    elif e == '*':
        q.append(q.pop() * q.pop())
    else:
        q.append(int(e))

print(q[0])