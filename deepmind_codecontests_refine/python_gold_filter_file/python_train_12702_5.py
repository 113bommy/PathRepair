def abc(a,b,c):
    if a==n:
        pass
    else:
        if b == 1:
            c += A[a]
            s.add(c)
        abc(a+1,0,c)
        abc(a+1,1,c)

n = int(input())
A = [int(a) for a in input().split()]
q = int(input())
M = [int(m) for m in input().split()]
s = set()

abc(0,0,0)
abc(0,1,0)

for m in M:
    if m in s:
        print("yes")
    else:
        print("no")