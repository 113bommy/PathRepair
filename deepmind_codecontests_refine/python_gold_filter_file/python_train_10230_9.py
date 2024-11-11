t = int(input())
def find(s, i, j):
    res = 0
    for ch in s:
        if ch == i:
            res += 1
            i,j = j,i
    if i!=j and res%2 == 1:
        res -= 1
    return res
for _ in range(t):
    s = input()
    correct = 0
    for i in range(10):
        for j in range(10):
            correct = max(correct, find(s,str(i),str(j)))
    print(len(s) - correct)