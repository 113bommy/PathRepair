def mfind(x):
    global m
    for i in range(len(m)):
        if m[i] != x:
            return i
def mrfind(x):
    global m,a
    for i in range(len(m)-1,-1,-1):
        if m[i] != x:
            return (a-i)-1
a=int(input())
m=list(map(int,input().split()))
if m[0] != m[-1]:
    print(a-1)
else:
    print(max(a-(mfind(m[0])+1),a-mrfind(m[-1])-1))
