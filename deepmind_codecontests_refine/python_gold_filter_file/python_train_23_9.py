import sys

tokens = input().split()
n, nb_required = int(tokens[0]), int(tokens[1])
both_liked = []
alice_liked = []
bob_liked = []
for i in range(n):
    tokens = input().split()
    t, a, b = int(tokens[0]), int(tokens[1]), int(tokens[2])
    if a == 1 and b == 1:
        both_liked.append(t)
    elif a == 1:
        alice_liked.append(t)
    elif b == 1:
        bob_liked.append(t)

both_liked.sort()
alice_liked.sort()
bob_liked.sort()

i = 0
j = 0
k = 0
total = 0
while nb_required > 0:
    if k < len(both_liked):
        if i == len(alice_liked) or j == len(bob_liked) or both_liked[k] <= alice_liked[i] + bob_liked[j]:
            nb_required -= 1
            total += both_liked[k]
            k += 1
            continue
    
    if i == len(alice_liked) or j == len(bob_liked):
        print(-1)
        sys.exit(0)
    
    nb_required -= 1
    total += alice_liked[i] + bob_liked[j]
    i += 1
    j += 1

print(total)




