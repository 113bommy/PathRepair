N, M = map(int, input().split())
Ai = [list(map(int, input().split())) for _ in range(M)]
 
groups = [-1 for i in range(N + 1)] #0番目は使わない
sizes = [1 for _ in range(N + 1)]
Ai.reverse()
 
value = N * (N - 1) // 2
answers = []
answers.append(value)
 
def parent(n):
    if groups[n] < 0:
        return n
    return parent(groups[n])
 
for a in Ai:
    if value <= 0:
        answers.append(0)
        continue
    p1 = parent(a[0])
    p2 = parent(a[1])
    if p1 == p2:
        answers.append(value)
        continue
 
    value -= sizes[p1] * sizes[p2]
    if p1 > p2:
        sizes[p2] += sizes[p1]
        groups[p1] = p2
    else:
        sizes[p1] += sizes[p2]
        groups[p2] = p1
    answers.append(value)
 
answers.reverse()
answers = answers[1:]
for a in answers:
    print(a)