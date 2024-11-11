n = int(input())

sessions_orig = [int(sdfg) for sdfg in input().split()]

sessions = []

for s in sessions_orig:
    if s == 0:
        sessions.append(0)
        continue
    if s % 2 == 1:
        sessions.append(1)
    if s % 2 == 0:
        sessions.append(2)

for ses in range(n - 1):
    if sessions[ses] == 1:
        if sessions[ses + 1] != 0:
            sessions[ses] -= 1
            sessions[ses + 1] -= 1
        else:
            print("NO")
            exit()
    elif sessions[ses] == 0:
        continue
    elif sessions[ses] == 2:
        sessions[ses] -= 2

if sessions[n - 1] == 1:
    print("NO")
    exit()

print("YES")

