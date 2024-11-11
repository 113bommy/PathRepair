n,t = map(int,input().split(" "))
q = input()
klist = list(i for i in q)
for _ in range(t):
    i = 0
    while i < n-1:
        if klist[i] == "B" and klist [i+1] == "G":
            klist[i],klist[i+1] = klist[i+1],klist[i]
            i += 1
        i += 1
print("".join(klist))