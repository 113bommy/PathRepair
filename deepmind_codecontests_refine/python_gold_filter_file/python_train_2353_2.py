from sys import stdin, stdout
n,k,q = map(int,stdin.readline().rstrip().split())

c = [0] * 200002

for i in range(n):
    a,b = map(int, input().split(' '))
    c[a]+=1
    c[b+1]-=1

for i in range(1,len(c)):
    c[i] = c[i] + c[i-1]

for i in range(0, len(c)):
    c[i] = 1 if c[i] >= k else 0


for i in range(1,len(c)):
    c[i] = c[i] + c[i-1]


for i in range(q):
    a,b = map(int, stdin.readline().rstrip().split())
    stdout.write(str(c[b]-c[a-1])+ "\n")
