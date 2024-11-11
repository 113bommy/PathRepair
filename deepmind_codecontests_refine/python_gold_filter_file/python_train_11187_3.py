n, k = map(int, input().split());
towers = list(map(int, input().split()));
stow = sorted([[towers[i], i] for i in range(0, n)], key = lambda k: k[0]);
operations = [];
for i in range(0, k):
    stow = sorted(stow, key = lambda k: k[0]);
    if(stow[n-1][0] <= stow[0][0]+1):
        break;
    stow[n-1][0] -= 1;
    stow[0][0] += 1;
    operations.append([stow[n-1][1]+1, stow[0][1]+1]);
stow = sorted(stow, key = lambda k: k[0]);
max_ins = stow[n-1][0] - stow[0][0];
print(max_ins, len(operations));
for op in operations:
    print(*op);

