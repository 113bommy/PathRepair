n = int(input())
w = 0
students = list(map(int, input().split()))
ones = []
twos = []
threes = []
for i, e in enumerate(students):
    if e == 1:
        ones.append([e, i + 1])
    elif e == 2:
        twos.append([e, i + 1])
    else:
        threes.append([e, i + 1])
if len(ones) >= 1 and len(twos) >= 1 and len(threes) >= 1:
    w = min(len(ones), len(twos), len(threes))    
print(w)
if w:
    for i in range(w):
        print(ones[i][1],twos[i][1], threes[i][1])