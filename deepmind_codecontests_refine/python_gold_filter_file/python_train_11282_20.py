stones = input()
instr = input()

curr = 0
for i in instr:
    if i == stones[curr]:
        curr += 1

print(curr + 1)