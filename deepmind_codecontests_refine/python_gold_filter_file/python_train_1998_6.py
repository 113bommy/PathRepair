(n, k) = list(map(int, input().split()))
Massage = []
id_all = list(map(int, input().split()))
A = set()
for i in range(n):
    id = id_all[i]
    if id not in A:
        Massage.append(id)
        A.add(id)
        if len(A) > k:
            A.remove(Massage[-k-1])

if len(Massage) > k:
    print(k)
    print(*Massage[-1:-(k+1):-1])
else:
    print(len(Massage))
    print(*Massage[::-1])