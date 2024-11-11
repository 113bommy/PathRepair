n = int(input())
A = list(map(int, input().split()))
q = int(input())
m = list(map(int, input().split()))
N = int(2**n)
d = []

for i in range(N):
    b = "{:0{}b}".format(i, n)
    d.append(sum(A[j] for j in range(n) if b[j] == '1'))

    #print(b)

for i in range(q):
    if m[i] in d:
        print("yes")
    else:
        print("no")