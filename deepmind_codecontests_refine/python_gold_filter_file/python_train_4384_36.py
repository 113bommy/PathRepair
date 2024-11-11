w,h,k = list(map(int,input().split()))

l = [[0 for i in range(h)] for i in range(w)]
s = 0
for i in range(k):

    for i in range(s,h-s):
        l[s][i] = 1
        l[-1-s][i] = 1

    for j in range(s,w-s):
        l[j][s] = 1
        l[j][-1-s] = 1

    s += 2

s = 0
for i in range(len(l)):
    for j in range(len(l[0])):
        if l[i][j] == 1:
            s += 1

print(s)
